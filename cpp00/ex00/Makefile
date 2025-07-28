CC = c++
CCFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = megaphone

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	@$(CC) $(CCFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean
