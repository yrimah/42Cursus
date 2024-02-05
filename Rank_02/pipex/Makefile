NAME		=	pipex
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

HEADER_SRCS	=	includes/pipex.h

SRCS	=	pipex.c child_processes.c handling.c free_process.c ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c ft_strlen.c
OBJS	=	$(SRCS:.c=.o)

%.o: %.c $(HEADER_SRCS)
				${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
