CC		=	cc
NAME	=	so_long
FLAGS	=	-Wall -Wextra -Werror

SRCS	=	src/handling.c src/check_map.c src/check_path.c src/add_anim.c \
			src/utils.c src/initialize.c src/set_items.c main.c

LIBS		=	libft

INCLUDES	=	$(LIBS:%=includes/$*/%.a)

MLX_flags	=	-lmlx -framework OpenGL -framework AppKit

all: $(LIBS) $(NAME)
	@:
$(NAME): $(SRCS)
	$(CC) -I includes $(FLAGS) $(SRCS) $(INCLUDES) $(MLX_flags) -o $(NAME)
	
libs: $(LIBS)

$(LIBS):
	make -C includes/$@
	cp includes/$@/$@.a includes
clean:
	make -C includes/libft clean

fclean: clean
	make -C includes/libft fclean
	rm -rf $(NAME)
	rm -rf $(INCLUDES)

re: fclean all

.PHONY: all