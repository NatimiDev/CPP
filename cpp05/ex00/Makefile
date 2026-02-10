FLAGS := -Wall -Wextra -Werror
NAME := ex00

OBJDIR := obj

SRCS := main.cpp Bureaucrat.cpp
HEADERS := Bureaucrat.hpp

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(FLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	g++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
