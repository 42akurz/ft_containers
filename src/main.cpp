#include "../container/vector.hpp"
#include "../container/map.hpp"
#include "../utils/red_black_tree.hpp"

#define TESTED_TYPE			std::string
#define TESTED_NAMESPACE	ft

int	main()
{
	ft::RBTree<ft::pair<int, char> > tree;
	
	tree.insert(ft::make_pair(10, 'g'));
	tree.insert(ft::make_pair(5, 'x'));
	tree.insert(ft::make_pair(20, 'k'));
	tree.insert(ft::make_pair(3, 'b'));
	tree.insert(ft::make_pair(8, 'e'));
	tree.insert(ft::make_pair(15, 'i'));
	tree.insert(ft::make_pair(25, 'm'));
	tree.insert(ft::make_pair(1, 'a'));
	tree.insert(ft::make_pair(4, 'c'));
	tree.insert(ft::make_pair(7, 'd'));
	tree.insert(ft::make_pair(9, 'f'));
	tree.insert(ft::make_pair(12, 'h'));
	tree.insert(ft::make_pair(17, 'j'));
	tree.insert(ft::make_pair(21, 'l'));
	tree.insert(ft::make_pair(30, 'n'));

	// std::cout << (tree._root->left->left->left->val) << std::endl;
	
	ft::RBTree<ft::pair<int, char> >::iterator	it = tree.begin();

	std::cout << it->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;
	std::cout << (++it)->first << "\t|\t" << it->second << std::endl;

	tree.deleteByVal(ft::pair<int, char>(17, 'j'));
	tree.deleteByVal(ft::pair<int, char>(8, 'e'));
	it = tree.begin();
	std::cout << std::endl;

	std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	std::cout << (it)->first << "\t|\t" << it->second << std::endl;
	// std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	// std::cout << (it++)->first << "\t|\t" << it->second << std::endl;
	// std::cout << (it)->first << "\t|\t" << it->second << std::endl;

	// system("leaks containers");


	return 0;


}
