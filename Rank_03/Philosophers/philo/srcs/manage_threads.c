/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:08:28 by yrimah            #+#    #+#             */
/*   Updated: 2023/03/14 18:08:32 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosophers.h"

int	create_threads(t_philo **philos, t_args *params)
{
	int	current;

	params->start_time = get_timestamp();
	current = 0;
	while (current < params->num)
	{
		if (pthread_create(&((*philos)[current].thread), NULL,
			routine, &((*philos)[current])))
			return (0);
		current++;
	}
	if (pthread_create(&(params->death_thread), NULL,
			check_death, philos))
		return (0);
	return (1);
}

int	wait_threads(t_philo **philos, t_args *params)
{
	int	cur;
	int	return_code;

	cur = 0;
	return_code = 1;
	while (cur < params->num)
	{
		if (pthread_join((*philos)[cur].thread, NULL))
			return_code = 0;
		cur++;
	}
	return (return_code);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->pos % 2 != 0)
		ft_usleep(philo->params->time_to_eat);
	while (!is_dead(philo))
	{
		if (philo->meal_count >= philo->params->meal_max
			&& philo->params->meal_max > 0)
			break ;
		take_fork('l', philo);
		if (philo->l_taken)
			take_fork('r', philo);
		if (philo->r_taken && philo->l_taken)
		{
			write_state("is eating", philo);
			ft_usleep(philo->params->time_to_eat);
			philo->meal_count++;
			pthread_mutex_lock(&(philo->m_last_meal));
			philo->last_meal = get_timestamp() - philo->params->start_time;
			pthread_mutex_unlock(&(philo->m_last_meal));
			release_forks_and_sleep(philo);
		}
	}
	return (NULL);
}
