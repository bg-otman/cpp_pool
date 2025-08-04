CC = c++
CCFLAGS = -std=c++98 -Wall -Wextra #-Werror
SRCS = main.cpp phonebook.cpp contact.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = PhoneBook.hpp Contact.hpp
NAME =  phonebook

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	@$(CC) $(CCFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean
