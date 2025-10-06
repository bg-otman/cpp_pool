CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = AMateria.hpp Ice.hpp Cure.hpp
NAME = Polymorphism

all : $(NAME)

$(NAME) : $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean

.SECONDARY : $(OBJS)
