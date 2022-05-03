NAME = containers

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ./src/main.cpp		\

INC = ./inc/vector.hpp		\

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
