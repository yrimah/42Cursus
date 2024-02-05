/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:12:36 by yrimah            #+#    #+#             */
/*   Updated: 2023/02/07 16:12:38 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	extention(char *str)
{
	int	position;

	position = ft_strlen(str) - 4;
	if (ft_strncmp(str + position, ".ber", 4))
		return (1);
	return (0);
}

int	validate(t_game *game, char *filename, t_image *img)
{
	if (extention(filename))
		return (set_error(game, "Unauthorized/Invalid file name"));
	else if (map(game, filename))
		return (set_error(game, "Problem in the input file"));
	else if (closed_map(game))
		return (set_error(game, "Problem in map's walls"));
	else if (rectangle_map(game))
		return (set_error(game, "Unauthorized/Invalid Map"));
	else if (token_type(game))
		return (set_error(game, "Unauthorized/Invalid token"));
	else if (token_count(game))
		return (set_error(game, "Token not found/duplicate"));
	game->map2 = map_duplicate(game);
	allow_a(game->pos_x, game->pos_y, game->map2);
	if (check_item(game, 'C'))
		return (set_error(game, "Found unreachable collectibles"));
	allow_b(game->pos_x, game->pos_y, game->map2);
	if (check_item(game, 'E'))
		return (set_error(game, "Player exit problem"));
	free_map(game->map2);
	game->mlx = mlx_init();
	player_initialize(game, img);
	img_initialize(game, img);
	return (0);
}

int	set_error(t_game *game, char *msg)
{
	game->error = msg;
	return (1);
}
