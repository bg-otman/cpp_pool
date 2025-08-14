CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Zombie.hpp
NAME = BraiiiiiiinnnzzzZ

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
# 	@rm -f $(OBJS)
	@del  $(OBJS)

fclean : clean
# 	@rm -f $(NAME)
	@del  $(NAME:=.exe)

re : fclean all

.PHONY : clean
