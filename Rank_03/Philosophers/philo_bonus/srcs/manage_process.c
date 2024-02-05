/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:57:02 by yrimah            #+#    #+#             */
/*   Updated: 2023/03/15 11:57:06 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosophers.h"

int	create_process(t_philo **philos, t_args *params)
{
	int	cur;

	params->start_time = get_timestamp();
	cur = 0;
	while (cur < params->num)
	{
		(*philos)[cur].pid = fork();
		if ((*philos)[cur].pid == 0)
			return (routine(&((*philos)[cur])));
		cur++;
	}
	if (pthread_create(&(params->death_thread), NULL,
			wait_death, philos))
		return (0);
	return (1);
}

int	wait_process(t_philo **philos, t_args *params)
{
	int	cur;
	int	return_code;

	cur = 0;
	return_code = 1;
	while (cur < params->num)
	{
		if (waitpid((*philos)[cur].pid, NULL, 0) == -1)
			return_code = 0;
		cur++;
	}
	return (return_code);
}

int	routine(t_philo *philo)
{
	pthread_t	death_thread;

	pthread_create(&death_thread, NULL, check_death, philo);
	if (philo->pos % 2 != 0)
		ft_usleep(philo->params->time_to_eat);
	while (1)
	{
		if (philo->meal_count >= philo->params->meal_max
			&& philo->params->meal_max > 0)
			break ;
		take_fork(philo);
		take_fork(philo);
		write_state("is eating", philo);
		ft_usleep(philo->params->time_to_eat);
		philo->meal_count++;
		sem_wait(philo->sem_last_meal);
		philo->last_meal = get_timestamp() - philo->params->start_time;
		sem_post(philo->sem_last_meal);
		release_forks_and_sleep(philo);
		ft_usleep((philo->params->time_to_die - philo->params->time_to_eat
				- philo->params->time_to_sleep) / 2);
	}
	sem_post(philo->params->finished);
	return (1);
}
