NAME = containers

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	./src/main.cpp		\

INC =	./container/vector.hpp	\
		./iterator/iterator.hpp	\
		./iterator/iterator_traits.hpp	\
		./iterator/vector_iterator.hpp	\
		./iterator/reverse_iterator.hpp	\
		./utils/enable_if.hpp	\
		./utils/lexicographical_compare.hpp \
		./utils/equal.hpp \

RM = rm -f

all: $(NAME)

$(NAME): $(SRC) $(INC)
	$(CC) $(CFLAGS) $(SRC) -o $@

test: $(SRC) $(INC)
	$(CC) $(SRC) -o $@

clean: fclean

fclean:
	$(RM) $(NAME)

re: fclean all
