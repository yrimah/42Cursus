NAME	:=	megaphone

CC		:=	c++
WFLAGS	:=	-Wall -Wextra -Werror
CPPFLAGS	:=	-std=c++98

SRCS	:=	megaphone.cpp

OBJS	:=	$(SRCS:.cpp=.o)

%.o:%.c 
	$(CC) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(WFLAGS) -o $@

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re