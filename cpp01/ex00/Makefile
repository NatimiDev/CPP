FLAGS := -Wall -Wextra -Werror
NAME := zombie
FILES := main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all: ${NAME}

${NAME}: ${FILES}
	g++ ${FLAGS} ${FILES} -o ${NAME}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all
