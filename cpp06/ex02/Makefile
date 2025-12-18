CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Base.hpp
NAME = identify_type

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✓ Compilation complete! Executable: $(NAME)"

%.o : %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean
.SECONDARY : $(OBJS)