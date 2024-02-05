/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:12:44 by yrimah            #+#    #+#             */
/*   Updated: 2023/02/07 16:12:46 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	game_initialize(t_game *game)
{
	game->frame = DEFAULT;
	game->moves = DEFAULT;
	game->len = DEFAULT;
	game->lines = DEFAULT;
	game->pos = DEFAULT;
	game->colct = DEFAULT;
	game->exit = DEFAULT;
	game->end = DEFAULT;
}

void	player_initialize(t_game *game, t_image *img)
{
	img->player_right = mlx_xpm_file_to_image(
			game->mlx, "img/player_right_1.xpm",
			&img->img_width, &img->img_height);
	img->player_left = mlx_xpm_file_to_image(game->mlx, "img/player_left_1.xpm",
			&img->img_width, &img->img_height);
	img->player_up = mlx_xpm_file_to_image(game->mlx, "img/player_up_1.xpm",
			&img->img_width, &img->img_height);
	img->player_down = mlx_xpm_file_to_image(game->mlx, "img/player_down_1.xpm",
			&img->img_width, &img->img_height);
}

void	img_initialize(t_game *game, t_image *img)
{
	img->game = game;
	img->wall = mlx_xpm_file_to_image(game->mlx, "img/wall_1.xpm",
			&img->img_width, &img->img_height);
	img->coll = mlx_xpm_file_to_image(game->mlx, "img/collectible_1.xpm",
			&img->img_width, &img->img_height);
	img->floor = mlx_xpm_file_to_image(game->mlx, "img/floor_1.xpm",
			&img->img_width, &img->img_height);
	img->opened = mlx_xpm_file_to_image(game->mlx, "img/opened_1.xpm",
			&img->img_width, &img->img_height);
	img->closed = mlx_xpm_file_to_image(game->mlx, "img/closed_1.xpm",
			&img->img_width, &img->img_height);
	img->enm0 = mlx_xpm_file_to_image(game->mlx, "img/enm_00.xpm",
			&img->img_width, &img->img_height);
	img->enm1 = mlx_xpm_file_to_image(game->mlx, "img/enm_02.xpm",
			&img->img_width, &img->img_height);
	img->winner = mlx_xpm_file_to_image(game->mlx, "img/winner.xpm",
			&img->img_width, &img->img_height);
	img->loser = mlx_xpm_file_to_image(game->mlx, "img/loser.xpm",
			&img->img_width, &img->img_height);
	img->player = img->player_down;
	img->enm = img->enm0;
}
