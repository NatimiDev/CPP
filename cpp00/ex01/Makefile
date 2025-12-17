FLAGS := -Wall -Wextra -Werror
NAME := phonebook
FILES := Contact.cpp PhoneBook.cpp

all: $(NAME)

$(NAME): $(FILES)
	g++ $(FLAGS) $(FILES) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
