NAME		:=	philo
CC			:=	cc -Wall -Wextra -Werror
FLAGS		:=	-lpthread

DIR_SRCS	:=	srcs
DIR_INCS	:=	include

SRCS_FILES	:=	manage_death.c \
				manage_forks.c \
				initialize.c \
				main.c \
				manage_threads.c \
				help.c
OBJS	:=	$(SRCS_FILES:.c=.o)
INCS_FILES	:=	philosophers.h

SRCS		:=	$(addprefix $(DIR_SRCS)/, $(SRCS_FILES))
INCS		:=	$(addprefix $(DIR_INCS)/, $(INCS_FILES))

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
