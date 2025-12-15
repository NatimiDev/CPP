FLAGS := -Wall -Wextra -Werror -std=c++98
NAME := phonebook
FILES := Account.cpp tests.cpp

all: ${NAME}

${NAME}: ${FILES}
	g++ ${FLAGS} ${FILES} -o ${NAME}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all
