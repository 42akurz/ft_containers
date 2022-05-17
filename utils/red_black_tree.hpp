#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "log_colors.hpp"
# include <iostream>
# include <memory>
# include <queue>

/*
	Rules That Every Red-Black Tree Follows: 
	1.	Every node has a colour either red or black.
	2.	The root of the tree is always black.
	3.	There are no two adjacent red nodes (A red node cannot have a red parent or red child).
	4.	Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
	5.	All leaf nodes are black nodes. (NULL)
*/

enum COLOR {
	BLACK,
	RED,
};

namespace ft {
 
	template<class T>
	class tree_node {

		public:
			typedef		T			value_type;
			typedef		tree_node*	node_pointer;

		public:
			value_type		val;
			COLOR			color;
			node_pointer	left;
			node_pointer	right;
			node_pointer	parent;
		
			tree_node( value_type val ) : val(val) {
				parent = left = right = NULL;
				color = RED;
			}
		
			// returns pointer to uncle
			node_pointer	uncle() {
				// If no parent or grandparent, then no uncle
				if (parent == NULL || parent->parent == NULL)
					return NULL;
				if (parent->isOnLeft()) // uncle on right
					return parent->parent->right;
				else // uncle on left
					return parent->parent->left;
			}
		
			// check if node is left child of parent
			bool	isOnLeft() { return this == parent->left; }
			
			// returns pointer to sibling
			node_pointer	sibling() {
				// sibling null if no parent
				if (parent == NULL)
					return NULL;
				if (isOnLeft())
					return parent->right;
				return parent->left;
			}
		
			// moves node down and moves given node in its place
			void	moveDown( node_pointer nParent ) {
				if (this->parent != NULL) {
					if (isOnLeft())
						parent->left = nParent;
					else
						parent->right = nParent;
				}
				nParent->parent = this->parent;
				this->parent = nParent;
			}
		
			bool	hasRedChild() {
				return ((left != NULL && left->color == RED) || (right != NULL && right->color == RED));
			}

	}; /* class tree_node */

	template<class T_node, class var_type>
	class tree_iterator {
		public:
			typedef ptrdiff_t						difference_type;
			typedef T_node							value_type;
			typedef T_node *						pointer;
			typedef T_node &						reference;
			typedef ft::bidirectional_iterator_tag	iterator_category;
	
		private:
			pointer	_ptr;

		public:
			tree_iterator( pointer ptr = nullptr ) : _ptr(ptr) {}
			tree_iterator( const tree_iterator &in ) : _ptr(in._ptr) {}
			~tree_iterator() {}

			tree_iterator &		operator=( const tree_iterator & in ) { this->_ptr = in.base(); return *this; }

			// pointer				base() const { return _ptr; }

			var_type &			operator*() { return _ptr->val; }

			var_type *			operator->() { return &(operator*()); }
	
			tree_iterator &		operator++() {
				if (!_ptr)
					return *this;
				if (_ptr->right != NULL) {
					_ptr = _ptr->right;
					while (_ptr->left != NULL)
						_ptr = _ptr->left;
				}
				else {
					pointer	cur;
					cur = _ptr->parent;
					while (cur != NULL && cur->right == _ptr) {
						_ptr = cur;
						cur = _ptr->parent;
					}
					_ptr = cur;
				}
				return *this;
			}
	
	
	}; /* class tree_iterator */
		
	template< class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class RBTree {
		public:
			typedef				T										value_type;
			typedef				tree_node<value_type>					Node;
			typedef				tree_node<value_type> *					node_pointer;
			typedef				Alloc									allocator_type;
			typedef typename	Alloc::template rebind<Node>::other		node_allocator_type;
			typedef				Compare									value_compare;

			typedef				ft::tree_iterator<Node, value_type>		iterator;

			iterator	begin() {
				if (_root == NULL)
					return iterator(_root);
				node_pointer	tmp = _root;
				while (tmp->left != NULL)
					tmp = tmp->left;
				return iterator(tmp);
			}

		public:
			node_pointer	_root;
			value_compare	_compare;
			
			// left rotates the given node
			void	leftRotate( node_pointer x ) {
				// new parent will be node's right child
				node_pointer	nParent = x->right;
			
				// update root if current node is root
				if (x == _root)
					_root = nParent;

				x->moveDown(nParent);

				// connect x with new parent's left element
				x->right = nParent->left;
				// connect new parent's left element with node
				// if it is not null
				if (nParent->left != NULL)
					nParent->left->parent = x;
			
				// connect new parent with x
				nParent->left = x;
			}
			
			void	rightRotate( node_pointer x ) {
				// new parent will be node's left child
				node_pointer	nParent = x->left;
			
				// update root if current node is root
				if (x == _root)
					_root = nParent;
			
				x->moveDown(nParent);
			
				// connect x with new parent's right element
				x->left = nParent->right;
				// connect new parent's right element with node
				// if it is not null
				if (nParent->right != NULL)
					nParent->right->parent = x;
			
				// connect new parent with x
				nParent->right = x;
			}
			
			void	swapColors( node_pointer x1, node_pointer x2 ) {
				COLOR	temp;
				temp = x1->color;
				x1->color = x2->color;
				x2->color = temp;
			}
			
			void	swapValues( node_pointer u, node_pointer v ) {
				value_type	temp;
				temp = u->val;
				u->val = v->val;
				v->val = temp;
			}
			
			// fix red red at given node
			void	fixRedRed( node_pointer x ) {
				// if x is root color, make it black and return
				if (x == _root) {
					x->color = BLACK;
					return;
				}
			
				// initialize parent, grandparent, uncle
				node_pointer	parent = x->parent;
				node_pointer	grandparent = parent->parent;
				node_pointer	uncle = x->uncle();
			
				if (parent->color == RED) {
					if (uncle != NULL && uncle->color == RED) {
						// uncle red, perform recoloring and recurse
						parent->color = BLACK;
						uncle->color = BLACK;
						grandparent->color = RED;
						fixRedRed(grandparent);
					}
					else {
						// Else perform LR, LL, RL, RR
						if (parent->isOnLeft()) {
							if (x->isOnLeft()) {
								// for left right
								swapColors(parent, grandparent);
							}
							else {
								leftRotate(parent);
								swapColors(x, grandparent);
							}
							// for left left and left right
							rightRotate(grandparent);
						}
						else {
							if (x->isOnLeft()) {
								// for right left
								rightRotate(parent);
								swapColors(x, grandparent);
							}
							else {
								swapColors(parent, grandparent);
							}
					
							// for right right and right left
							leftRotate(grandparent);
						}
					}
				}
			}
			
			// find node that do not have a left child
			// in the subtree of the given node
			node_pointer	successor( node_pointer x ) {
				node_pointer	temp = x;
			
				while (temp->left != NULL)
					temp = temp->left;
			
				return temp;
			}
			
			// find node that replaces a deleted node in BST
			node_pointer	BSTreplace( node_pointer x ) {
				// when node have 2 children
				if (x->left != NULL && x->right != NULL)
					return successor(x->right);
			
				// when leaf
				if (x->left == NULL && x->right == NULL)
					return NULL;
			
				// when single child
				if (x->left != NULL)
					return x->left;
				else
					return x->right;
			}
			
			// deletes the given node
			void	deleteNode( node_pointer v ) {
				node_pointer	u = BSTreplace(v);
			
				// True when u and v are both black
				bool	uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK));
				node_pointer	parent = v->parent;
			
				if (u == NULL) {
					// u is NULL therefore v is leaf
					if (v == _root) {
						// v is root, making root null
						_root = NULL;
					}
					else {
						if (uvBlack) {
							// u and v both black
							// v is leaf, fix double black at v
							fixDoubleBlack(v);
						}
						else {
							// u or v is red
							if (v->sibling() != NULL) {
								// sibling is not null, make it red"
								v->sibling()->color = RED;
							}
						}
				
						// delete v from the tree
						if (v->isOnLeft()) {
							parent->left = NULL;
						}
						else {
							parent->right = NULL;
						}
					}
					delete v;
					return;
				}
			
				if (v->left == NULL || v->right == NULL) {
					// v has 1 child
					if (v == _root) {
						// v is root, assign the value of u to v, and delete u
						v->val = u->val;
						v->left = v->right = NULL;
						delete u;
					}
					else {
						// Detach v from tree and move u up
						if (v->isOnLeft()) {
							parent->left = u;
						}
						else {
							parent->right = u;
						}
						delete v;
						u->parent = parent;
						if (uvBlack) {
							// u and v both black, fix double black at u
							fixDoubleBlack(u);
						}
						else {
							// u or v red, color u black
							u->color = BLACK;
						}
					}
					return;
				}
			
				// v has 2 children, swap values with successor and recurse
				swapValues(u, v);
				deleteNode(u);
			}
			
			void	fixDoubleBlack( node_pointer x ) {
				if (x == _root) {
					// Reached root
					return;
				}
			
				node_pointer	sibling = x->sibling();
				node_pointer	parent = x->parent;
				if (sibling == NULL) {
					// No sibiling, double black pushed up
					fixDoubleBlack(parent);
				}
				else {
					if (sibling->color == RED) {
						// Sibling red
						parent->color = RED;
						sibling->color = BLACK;
						if (sibling->isOnLeft()) {
							// left case
							rightRotate(parent);
						}
						else {
							// right case
							leftRotate(parent);
						}
						fixDoubleBlack(x);
					}
					else {
						// Sibling black
						if (sibling->hasRedChild()) {
							// at least 1 red children
							if (sibling->left != NULL && sibling->left->color == RED) {
								if (sibling->isOnLeft()) {
									// left left
									sibling->left->color = sibling->color;
									sibling->color = parent->color;
									rightRotate(parent);
								}
								else {
									// right left
									sibling->left->color = parent->color;
									rightRotate(sibling);
									leftRotate(parent);
								}
							}
							else {
								if (sibling->isOnLeft()) {
									// left right
									sibling->right->color = parent->color;
									leftRotate(sibling);
									rightRotate(parent);
								}
								else {
									// right right
									sibling->right->color = sibling->color;
									sibling->color = parent->color;
									leftRotate(parent);
								}
							}
							parent->color = BLACK;
						}
						else {
							// 2 black children
							sibling->color = RED;
							if (parent->color == BLACK)
								fixDoubleBlack(parent);
							else
								parent->color = BLACK;
						}
					}
				}
			}
			
			// prints level order for given node
			void	levelOrder( node_pointer x ) {
				if (x == NULL) {
					// return if node is null
					return;
				}
			
				// queue for level order
				std::queue<node_pointer>	q;
				node_pointer				curr;
			
				// push x
				q.push(x);
			
				while (!q.empty()) {
					// while q is not empty
					// dequeue
					curr = q.front();
					q.pop();
				
					// print node value
					std::cout << curr->val << " ";
				
					// push children to queue
					if (curr->left != NULL)
						q.push(curr->left);
					if (curr->right != NULL)
						q.push(curr->right);
				}
			}
			
			// prints inorder recursively
			void	inorder( node_pointer x ) {
				if (x == NULL)
					return;
				inorder(x->left);
				std::cout << x->val << " ";
				inorder(x->right);
			}
		
		public:
			// constructor
			// initialize root
			RBTree() { _root = NULL; }
			
			node_pointer	getRoot() { return _root; }
			
			// searches for given value
			// if found returns the node (used for delete)
			// else returns the last node while traversing (used in insert)
			node_pointer	search( value_type n ) {
				node_pointer	temp = _root;
				while (temp != NULL) {
					if (n < temp->val) {
						if (temp->left == NULL)
							break;
						else
							temp = temp->left;
					}
					else if (n == temp->val) {
						break;
					}
					else {
						if (temp->right == NULL)
							break;
						else
							temp = temp->right;
					}
				}
				return temp;
			}
			
			// inserts the given value to tree
			void	insert( value_type n ) {
				node_pointer	newNode = new Node(n);
				if (_root == NULL) {
					// when root is null
					// simply insert value at root
					newNode->color = BLACK;
					_root = newNode;
				}
				else {
					node_pointer	temp = search(n);
				
					if (temp->val == n) {
						// return if value already exists
						return;
					}
				
					// if value is not found, search returns the node
					// where the value is to be inserted
				
					// connect new node to correct node
					newNode->parent = temp;
				
					if (n < temp->val)
						temp->left = newNode;
					else
						temp->right = newNode;
				
					// fix red red voilaton if exists
					fixRedRed(newNode);
				}
			}
			
			// utility function that deletes the node with given value
			void	deleteByVal( value_type n ) {
				if (_root == NULL) {
					// Tree is empty
					return;
				}
			
				node_pointer	v = search(n);
				// node_pointer	u;
			
				if (v->val != n) {
					std::cout << "No node found to delete with value:" << n << std::endl;
					return;
				}
			
				deleteNode(v);
			}
			
			// prints inorder of the tree
			void	printInOrder() {
				std::cout << "Inorder: " << std::endl;
				if (_root == NULL)
					std::cout << "Tree is empty" << std::endl;
				else {
					inorder(_root);
					std::cout << std::endl;
				}
			}
			
			// prints level order of the tree
			void	printLevelOrder() {
				std::cout << "Level order: " << std::endl;
				if (_root == NULL)
					std::cout << "Tree is empty" << std::endl;
				else {
					levelOrder(_root);
					std::cout << std::endl;
				}
			}
	}; /* class tree */
} /* namespace ft */

// namespace ft {

// 	template<class T>
// 	struct tree_node {
// 		T			data;
// 		tree_node	*left;
// 		tree_node	*right;
// 		tree_node	*parent;
// 		bool		color;
// 	};

// 	template< class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
// 	class tree {

// 		public:
// 			typedef				T										value_type;
// 			typedef				tree_node<value_type>					node;
// 			typedef				tree_node<value_type> *					node_pointer;
// 			typedef				Alloc									allocator_type;
// 			typedef typename	Alloc::template rebind<node>::other		node_allocator_type;
// 			typedef				Compare									value_compare;

// 		public: // TODO: make private
// 			node_pointer		_root;
// 			allocator_type		_alloc;
// 			node_allocator_type	_node_alloc;
// 			value_compare		_compare;

// 		public:
// 			tree() { this->_root = nullptr; }
// 			~tree() {}

// 			// void	printTree( node_pointer current ) {
// 			// 	if (current == nullptr) {
// 			// 		std::cout << "\033[1;34m" << "NULL" << "\033[0m";
// 			// 		return ;
// 			// 	}
// 			// 	if (current->color == BLACK)
// 			// 		std::cout << "\033[1;30m" << current->data << "\033[0m";
// 			// 	if (current->color == RED)
// 			// 		std::cout << "\033[1;31m" << current->data << "\033[0m";
// 			// 	printTree(current->left);
// 			// 	std::cout << "\t\t";
// 			// 	printTree(current->right);
// 			// 	std::cout << std::endl;
// 			// }

// 			node_pointer	createNode( value_type in ) {
// 				node_pointer	newNode = _node_alloc.allocate(1);
// 				newNode->data = in;
// 				newNode->color = RED;
// 				newNode->left = nullptr;
// 				newNode->right = nullptr;
// 				newNode->parent = nullptr;
// 				return newNode;
// 			}

// 			void	insert( value_type in ) {
// 				node_pointer	newNode = createNode(in);
// 				if (_root == nullptr) {
// 					newNode->color = BLACK;
// 					_root = newNode;
// 				}
// 				else {
// 					node_pointer	finder = _root;
// 					while (true) {
// 						if (!_compare(newNode->data, finder->data)) {
// 							if (finder->right == NULL) {
// 								newNode->parent = finder;
// 								finder->right = newNode;
// 								return ;
// 							}
// 							else { finder = finder->right; }
// 						}
// 						if (_compare(newNode->data, finder->data)) {
// 							if (finder->left == NULL) {
// 								newNode->parent = finder;
// 								finder->left = newNode;
// 								return ;
// 							}
// 							else { finder = finder->left; }
// 						}
// 					}
// 				}
// 			}

// 	}; /* class tree */

// } /* namespace ft */

#endif