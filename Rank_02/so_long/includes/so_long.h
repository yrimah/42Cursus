/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:13:40 by yrimah            #+#    #+#             */
/*   Updated: 2023/02/07 16:13:42 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>

# define DEFAULT 0
# define A 0
# define D 2
# define S 1
# define W 13
# define ESC 53

typedef struct s_game
{
	int		frame;
	int		moves;
	int		len;
	int		lines;
	int		pos;
	int		colct;
	int		exit;
	int		pos_x;
	int		pos_y;
	int		end;
	char	**map;
	char	**map2;
	char	*error;
	char	*score;
	char	*score_i;
	char	*msg;
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;
}	t_game;

typedef struct s_image
{
	t_game	*game;
	int		img_width;
	int		img_height;
	void	*player;
	void	*player_right;
	void	*player_left;
	void	*player_up;
	void	*player_down;
	void	*wall;
	void	*coll;
	void	*floor;
	void	*opened;
	void	*closed;
	void	*enm;
	void	*enm0;
	void	*enm1;
	void	*winner;
	void	*loser;
}	t_image;

void	game_initialize(t_game *game);
void	player_initialize(t_game *game, t_image *img);
void	img_initialize(t_game *game, t_image *img);
int		validate(t_game *game, char *filename, t_image *img);
int		map(t_game *game, char *filename);
int		ft_length(char *line);
int		rectangle_map(t_game *game);
int		closed_map(t_game *game);
int		token_type( t_game *game);
int		token_count(t_game *game);
char	**map_duplicate(t_game *game);
void	allow_a(int pos_x, int pos_y, char **map);
void	allow_b(int pos_x, int pos_y, char **map);
int		check_item(t_game *game, char c);
void	free_map(char **map);
int		set_error(t_game *game, char *msg);
void	set_items(t_image *img);
void	put_img(t_game *game, void *img, int i, int j);
int		put_hint(t_game *game, char *msg);
int		keys(int key, t_image *img);
void	move_player(t_game *game, t_image *img, int x, int y);
int		animate( t_image *img);
int		quit(t_game *game);

#endif
