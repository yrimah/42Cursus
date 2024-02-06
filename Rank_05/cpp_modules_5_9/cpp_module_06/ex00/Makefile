NAME	:= convert

CC		:=	c++
FLAGS	:=	-Wall -Wextra -Werror #-fsanitize=address
CFLAGS	:=	-std=c++98

SRCS	:=	main.cpp ScalarConverter.cpp
INCS	:=	ScalarConverter.hpp

OBJS	:=	$(SRCS:.cpp=.o)

%.o:%.c 
	$(CC) -I $(INCS) -c $< -o $@

all:		$(NAME)

$(NAME): $(INCS) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(FLAGS) -o $@

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
