NAME	=	push_swap
CNAME	=	checker

CFLAGS	=	-Wall -Wextra -Werror
CC		=	cc
RM		=	rm -rf

_SRCS	=	program.c helps.c stack_help_1.c stack_help_2.c \
			handling.c actions_1.c actions_2.c actions_3.c \
			tiny_sort.c sort_stack.c stack_position.c push_swap_exec.c
			
SRCS	=	$(addprefix srcs/, $(_SRCS))
OBJS	=	$(SRCS:.c=.o)

_CSRCS	=	helpers.c
CSRCS	=	$(addprefix bonus/, $(_CSRCS))
COBJS	=	$(CSRCS:.c=.o)

.c.o	:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) srcs/main.o
			make -C libft/
			$(CC) $(CFLAGS) -L libft/ -lft srcs/main.o $(OBJS) -o $(NAME)

bonus	:	$(OBJS) $(COBJS) bonus/main.o
			make -C libft/
			$(CC) $(CFLAGS) -L libft/ -lft bonus/main.o $(OBJS) $(COBJS) -o $(CNAME)

clean	:
			$(RM) $(OBJS) $(COBJS) srcs/main.o bonus/main.o
			make clean -C libft/

fclean	:	clean
			$(RM) $(NAME) $(CNAME)
			make fclean -C libft/

re		:	fclean all

.PHONY	:	all clean fclean re bonus
