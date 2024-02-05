/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:12:10 by yrimah            #+#    #+#             */
/*   Updated: 2023/02/08 15:32:21 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	move(t_game *game, char next, int x, int y)
{
	if (next == 'G' || (next == 'E' && game->colct == 0))
			game->end = 1;
	else if (next == 'C')
	{
		game->map[game->pos_x][game->pos_y] = '0';
		game->map[game->pos_x + x][game->pos_y + y] = 'P';
		game->pos_y += y;
		game->pos_x += x;
		game->colct--;
	}
	else if (next == '0')
	{
		game->map[game->pos_x][game->pos_y] = '0';
		game->map[game->pos_x + x][game->pos_y + y] = 'P';
		game->pos_y += y;
		game->pos_x += x;
	}
	else if (next == '1')
		return ;
}

void	move_player(t_game *game, t_image *img, int x, int y)
{
	char	next;

	next = game->map[game->pos_x + x][game->pos_y + y];
	if (next == '1' || (next == 'E' && game->colct != 0))
		return ;
	mlx_clear_window(game->mlx, game->mlx_win);
	game->moves++;
	move(game, next, x, y);
	if (game->end == 0)
		set_items(img);
	else if (next == 'G')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, img->loser,
			(game->len * 115 - 600) / 2, (game->lines * 115 - 400) / 2);
		game->end = 1;
		put_hint(game, "Exit with ESC");
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, img->winner,
			(game->len * 115 - 600) / 2, (game->lines * 115 - 400) / 2);
		game->end = 1;
		put_hint(game, "Exit with ESC");
	}
}

int	keys(int key, t_image *img)
{
	if (key == ESC)
		exit(0);
	else if (key == W)
	{
		img->player = img->player_up;
		move_player(img->game, img, -1, 0);
	}
	else if (key == S)
	{
	img->player = img->player_down;
		move_player(img->game, img, 1, 0);
	}
	else if (key == A)
	{
			img->player = img->player_left;
		move_player(img->game, img, 0, -1);
	}
	else if (key == D)
	{
		img->player = img->player_right;
		move_player(img->game, img, 0, 1);
	}
	return (0);
}

int	quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

int	animate(t_image *img)
{	
	if (img->game->frame == 6000 && img->game->end == 0)
	{
		img->enm = img->enm1;
		set_items(img);
	}
	else if (img->game->frame == 12000 && img->game->end == 0)
	{
		img->enm = img->enm0;
		set_items(img);
		img->game->frame = 0;
	}
	img->game->frame++;
	return (0);
}
