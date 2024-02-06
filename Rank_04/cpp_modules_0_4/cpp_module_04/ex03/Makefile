NAME	:=	program

CC		:=	c++
FLAGS	:=	-Wall -Wextra -Werror #-fsanitize=address -fno-omit-frame-pointer
CFLAGS	:=	-std=c++98

SRCS	:=	AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
INCS	:=	AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp IMateriaSource.hpp Ice.hpp MateriaSource.hpp

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
