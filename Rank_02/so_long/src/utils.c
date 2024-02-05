/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:12:59 by yrimah            #+#    #+#             */
/*   Updated: 2023/02/07 16:13:01 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**map_duplicate(t_game *game)
{
	int		i;
	char	**map2;

	i = 0;
	map2 = (char **)malloc(sizeof(char *) * (game->lines + 1));
	while (game->map[i])
	{
		map2[i] = ft_strdup(game->map[i]);
		i ++;
	}
	map2[i] = NULL;
	return (map2);
}

int	ft_length(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	map(t_game *game, char *filename)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		game->lines++;
		free(line);
		line = get_next_line(fd);
	}
	if (!game->lines)
		return (1);
	close(fd);
	game->map = (char **)malloc(sizeof(char *) * (game->lines + 1));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < game->lines)
		game->map[i++] = get_next_line(fd);
	game->map[i] = NULL;
	return (0);
}
