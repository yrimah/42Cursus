/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:12:28 by yrimah            #+#    #+#             */
/*   Updated: 2023/02/07 16:12:30 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

// allow_A - allow_B : check where the player can navigate & mark it with A & B
void	allow_a(int pos_x, int pos_y, char **map)
{
	if ((map[pos_x][pos_y] != 'P' && map[pos_x][pos_y] != 'C'
	&& map[pos_x][pos_y] != '0'))
		return ;
	map[pos_x][pos_y] = 'A';
	allow_a(pos_x + 1, pos_y, map);
	allow_a(pos_x, pos_y + 1, map);
	allow_a(pos_x, pos_y - 1, map);
	allow_a(pos_x - 1, pos_y, map);
	return ;
}

void	allow_b(int pos_x, int pos_y, char **map)
{
	if ((map[pos_x][pos_y] != 'A' && map[pos_x][pos_y] != 'E'
	&& map[pos_x][pos_y] != '0'))
		return ;
	map[pos_x][pos_y] = 'B';
	allow_b(pos_x + 1, pos_y, map);
	allow_b(pos_x, pos_y + 1, map);
	allow_b(pos_x, pos_y - 1, map);
	allow_b(pos_x - 1, pos_y, map);
	return ;
}
