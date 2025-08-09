CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Account.hpp
NAME = Account

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean
