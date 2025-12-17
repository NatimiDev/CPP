FLAGS := -Wall -Wextra -Werror
NAME := ex03
FILES := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
all: ${NAME}

${NAME}: ${FILES}
	g++ ${FLAGS} ${FILES} -o ${NAME}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all
