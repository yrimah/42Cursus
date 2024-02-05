/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:13:30 by yrimah            #+#    #+#             */
/*   Updated: 2023/02/07 16:13:32 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	error(t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(game->error, 2);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_image	img;
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid number of args\n", 2);
		exit(1);
	}
	game_initialize(&game);
	if (validate(&game, argv[1], &img))
		error(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.len * 115,
			(game.lines + 1) * 115, "so_long");
	set_items(&img);
	mlx_key_hook(game.mlx_win, keys, &img);
	mlx_loop_hook(game.mlx, animate, &img);
	mlx_hook(game.mlx_win, 17, 0, quit, &game);
	mlx_loop(game.mlx);
	return (0);
}
