CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Bureaucrat.hpp Form.hpp
NAME = Form

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

.PHONY : clean
.SECONDARY : $(OBJS)