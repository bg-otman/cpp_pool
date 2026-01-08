CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Span.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Span.hpp
NAME = Span
RED = \033[0;31m

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✓ Compilation complete! \n✓ Executable: $(RED)./$(NAME)"

%.o : %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean
.SECONDARY : $(OBJS)