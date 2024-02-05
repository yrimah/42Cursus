/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:12:52 by yrimah            #+#    #+#             */
/*   Updated: 2023/02/07 16:12:54 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	set_floor(t_game *game, t_image *img)
{
	int	counter1;
	int	counter2;

	counter1 = -1;
	while (game->map[++counter1])
	{
		counter2 = -1;
		while (game->map[counter1][++counter2])
		{
			put_img(game, img->floor, counter1, counter2);
			if (game->map[counter1][counter2] == '1')
				put_img(game, img->wall, counter1, counter2);
		}
	}
}

static void	set_map(t_game *game, t_image *img)
{
	int	i;
	int	j;

	i = -1 ;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				put_img(game, img->coll, i, j);
			else if (game->map[i][j] == 'P')
				put_img(game, img->player, i, j);
			else if (game->map[i][j] == 'E' && game->colct == 0)
				put_img(game, img->opened, i, j);
			else if (game->map[i][j] == 'E')
				put_img(game, img->closed, i, j);
			else if (game->map[i][j] == 'G')
				put_img(game, img->enm, i, j);
		}
	}
}

int	put_hint(t_game *game, char *msg)
{
	char	*moves;
	char	*str;

	moves = ft_itoa(game->moves);
	str = ft_strjoin(msg, moves);
	if (game->end == 0)
		mlx_string_put(game->mlx, game->mlx_win, 0, 0, 0x00996600, str);
	mlx_string_put(game->mlx, game->mlx_win, 0, 0, 0x00996600, msg);
	free(moves);
	free(str);
	return (0);
}

void	put_img(t_game *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img,
		j * 115, (i + 1) * 115);
	put_hint(game, "Moves : ");
}

void	set_items(t_image *img)
{
	set_floor(img->game, img);
	set_map(img->game, img);
}
