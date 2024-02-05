/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:42 by yrimah            #+#    #+#             */
/*   Updated: 2023/03/15 11:56:46 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosophers.h"

int	stop_process(t_philo **philos, t_args *params)
{
	int	cur;

	cur = 0;
	while (cur < params->num)
		kill((*philos)[cur++].pid, SIGTERM);
	return (EXIT_FAILURE);
}

void	*check_death(void *arg)
{
	int		cur_time;
	t_philo	*philo;
	t_args	*params;

	philo = (t_philo *)arg;
	params = philo->params;
	while (1)
	{
		cur_time = get_timestamp() - params->start_time;
		if (cur_time - philo->last_meal > philo->params->time_to_die)
		{
			sem_wait(philo->params->sem_console);
			printf("%09d %d died\n", cur_time, philo->pos);
			sem_post(philo->params->finished);
		}
		ft_usleep(1);
	}
	return (NULL);
}

void	*wait_death(void *arg)
{
	t_philo	**philos;
	t_args	*params;

	philos = (t_philo **)arg;
	params = philos[0]->params;
	sem_wait(params->finished);
	stop_process(philos, params);
	return (NULL);
}
