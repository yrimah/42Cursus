NAME	:=	program

CC		:=	c++
FLAGS	:=	-Wall -Wextra -Werror #-fsanitize=address
CFLAGS	:=	-std=c++98

SRCS	:=	main.cpp AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp #WrongAnimal.cpp WrongCat.cpp
INCS	:=	AAnimal.hpp Dog.hpp Cat.hpp Brain.hpp #WrongAnimal.hpp WrongCat.hpp

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
