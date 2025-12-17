FLAGS := -Wall -Wextra -Werror -std=c++98
NAME := account
FILES := Account.cpp tests.cpp

all: ${NAME}

${NAME}: ${FILES}
	g++ ${FLAGS} ${FILES} -o ${NAME}

clean:

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
