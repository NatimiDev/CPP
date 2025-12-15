FLAGS := -Wall -Wextra -Werror
NAME := phonebook
FILES := Contact.cpp PhoneBook.cpp

all: ${NAME}

${NAME}: ${FILES}
	g++ ${FLAGS} ${FILES} -o ${NAME}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all
