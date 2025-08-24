CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Weapon.hpp HumanB.hpp HumanA.hpp
NAME = Weapon

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean

.SECONDARY : $(OBJS)
