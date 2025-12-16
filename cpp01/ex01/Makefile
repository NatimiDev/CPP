FLAGS := -Wall -Wextra -Werror
NAME := ex01
FILES := main.cpp Zombie.cpp zombieHorde.cpp

all: ${NAME}

${NAME}: ${FILES}
	g++ ${FLAGS} ${FILES} -o ${NAME}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all
