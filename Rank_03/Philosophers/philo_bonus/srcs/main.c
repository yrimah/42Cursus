/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:23 by yrimah            #+#    #+#             */
/*   Updated: 2023/03/15 11:56:26 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosophers.h"

static int	end_free(t_philo *philos, t_args *params, int code)
{
	free(philos);
	sem_close(params->sem_forks);
	sem_close(params->sem_console);
	sem_close(params->finished);
	return (code);
}

int	main(int argc, char *argv[])
{
	int		finish;
	t_args	params;
	t_philo	*philos;

	finish = 0;
	if (!init_args(&params, argc, argv))
		return (1);
	if (!create_philos(&philos, &params))
		return (1);
	if (!create_process(&philos, &params))
		finish = stop_process(&philos, &params);
	if (!wait_process(&philos, &params))
		return (end_free(philos, &params, 1));
	return (end_free(philos, &params, finish));
}
