NAME	:=	Sed

CC		:=	c++
FLAGS	:=	-Wall -Wextra -Werror #-fsanitize=address
CFLAGS	:=	-std=c++98

SRCS	:=	main.cpp File.cpp
INCS	:=	File.hpp
TESTS	:= .tests

OBJS	:=	$(SRCS:.cpp=.o)

%.o:%.c 
	$(CC) -I $(INCS) -c $< -o $@

all:		$(NAME)

$(NAME): $(INCS) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(FLAGS) -o $@

test:
	mkdir $(TESTS)
	touch $(TESTS)/test1 && chmod 000 $(TESTS)/test1
	echo "hi i am yassine from 42 network 1337 kh school" > $(TESTS)/test2
	echo "kh kg test3test2 \n \
		21337 kh 1337 bg kg \n \
		bg0kh test for sed programkh \n \
		kh" > $(TESTS)/test3

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME) $(TESTS)

re:			fclean all

.PHONY:		all clean fclean re
