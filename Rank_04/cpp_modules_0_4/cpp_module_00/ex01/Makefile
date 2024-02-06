NAME	:=	phonebook

CC		:=	c++
FLAGS	:=	-Wall -Wextra -Werror
CFLAGS	:=	-std=c++98

SRCS	:=	main.cpp Contact.cpp PhoneBook.cpp
INCS	:=	Contact.cpp PhoneBook.hpp

OBJS	:=	$(SRCS:.cpp=.o)

%.o:%.c 
	$(CC) -I $(INCS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(FLAGS) -o $@

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re