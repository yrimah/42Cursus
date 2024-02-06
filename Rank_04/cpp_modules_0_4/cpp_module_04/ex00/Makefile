NAME	:=	program

CC		:=	c++
FLAGS	:=	-Wall -Wextra -Werror #-fsanitize=address
CFLAGS	:=	-std=c++98

SRCS	:=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
INCS	:=	Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

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
