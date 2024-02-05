SRCS			=	ft_printf.c ft_print_p.c ft_printf_help.c ft_itoa.c ft_print_xX.c ft_print_u.c

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re 
