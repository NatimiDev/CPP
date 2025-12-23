FLAGS := -Wall -Wextra -Werror
NAME := ex04

SRCS := main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	g++ $(FLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
