/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:55:02 by yrimah            #+#    #+#             */
/*   Updated: 2023/03/14 09:55:08 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosophers.h"

static int	end_free(t_philo *philos, t_fork *forks, int code)
{
	free(philos);
	free(forks);
	return (code);
}

int	main(int argc, char *argv[])
{
	int			finish;
	t_args		args;
	t_philo		*philos;
	t_fork		*forks;

	finish = 0;
	if (!init_args(&args, argc, argv))
		return (1);
	if (!create_philos(&philos, &forks, &args))
		return (1);
	if (!create_threads(&philos, &args))
		finish = stop_threads(&philos[0]);
	if (!wait_threads(&philos, &args))
		return (end_free(philos, forks, 1));
	return (end_free(philos, forks, finish));
}
