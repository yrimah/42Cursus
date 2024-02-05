NAME		:=	philo_bonus

CC			:=	cc -Wall -Wextra -Werror
FLAGS		:=	-lpthread
DIR_SRCS	:=	srcs
DIR_INCS	:=	include

LST_SRCS	:=	manage_death.c \
				manage_forks.c \
				manage_process.c \
				initialize.c \
				help01.c \
				help02.c \
				main.c

OBJS	:=	$(LST_SRCS:.c=.o)
LST_INCS	:=	philosophers.h

SRCS		:=	$(addprefix $(DIR_SRCS)/, $(LST_SRCS))
INCS		:=	$(addprefix $(DIR_INCS)/, $(LST_INCS))

%.o: $(DIR_SRCS)/%.c $(INCS)
	$(CC) -I $(DIR_INCS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(FLAGS) -o $@

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re