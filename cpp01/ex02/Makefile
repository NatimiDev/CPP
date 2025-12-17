FLAGS := -Wall -Wextra -Werror
NAME := ex02
FILES := main.cpp
all: ${NAME}

${NAME}: ${FILES}
	g++ ${FLAGS} ${FILES} -o ${NAME}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all
