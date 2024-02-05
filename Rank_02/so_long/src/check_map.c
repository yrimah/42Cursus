/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:12:19 by yrimah            #+#    #+#             */
/*   Updated: 2023/02/07 16:12:22 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	rectangle_map(t_game *game)
{
	int	counter1;
	int	counter2;
	int	counter3;

	counter1 = 0;
	while (game->map[counter1])
	{
		if (ft_length(game->map[0]) == ft_length(game->map[counter1]))
			counter1++;
		else
			return (1);
	}
	counter2 = game->lines - 1;
	counter3 = ft_length(game->map[counter2]);
	if (game->map[counter2][counter3] == '\n')
		return (1);
	return (0);
}

int	closed_map(t_game *game)
{
	int	counter1;
	int	counter2;

	game->len = ft_length(game->map[0]);
	counter1 = 0;
	while (counter1 < game->lines)
	{
		counter2 = 0;
		while (counter2 < game->len)
		{
			if (counter1 == 0 || counter1 == game->lines - 1
				|| counter2 == 0 || counter2 == game->len - 1)
			{
				if (game->map[counter1][counter2] != '1')
					return (1);
			}
			counter2++;
		}
		counter1++;
	}
	return (0);
}

int	token_type( t_game *game)
{
	int	counter1;
	int	counter2;

	counter1 = 0;
	while (counter1 < game->lines)
	{
		counter2 = 0;
		while (counter2 < game->len)
		{
			if (game->map[counter1][counter2] != 'P'
					&& game->map[counter1][counter2] != 'E' &&
				game->map[counter1][counter2] != 'C'
				&& game->map[counter1][counter2] != '0' &&
				game->map[counter1][counter2] != '1'
				&& game->map[counter1][counter2] != 'G')
				return (1);
			counter2++;
		}
		counter1++;
	}
	return (0);
}

int	token_count(t_game *game)
{
	int	counter1;
	int	counter2;

	counter1 = 0;
	while (game->map[counter1])
	{	
		counter2 = -1;
		while (game->map[counter1][++counter2])
		{
			if (game->map[counter1][counter2] == 'E')
				game->exit++;
			if (game->map[counter1][counter2] == 'P')
			{
				game->pos++;
				game->pos_x = counter1;
				game->pos_y = counter2;
			}
			if (game->map[counter1][counter2] == 'C')
				game->colct++;
		}
		counter1++;
	}
	if (game->exit != 1 || game->pos != 1 || game->colct == 0)
		return (1);
	return (0);
}

int	check_item(t_game *game, char c)
{
	int	counter1;
	int	counter2;

	counter1 = 0;
	while (game->map2[counter1])
	{
		counter2 = 0;
		while (game->map2[counter1][counter2])
		{
			if (game->map2[counter1][counter2] == c)
				return (1);
			counter2++;
		}
		counter1++;
	}
	return (0);
}
