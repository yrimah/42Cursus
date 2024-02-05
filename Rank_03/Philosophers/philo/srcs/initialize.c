/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:59:49 by yrimah            #+#    #+#             */
/*   Updated: 2023/03/14 09:59:52 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosophers.h"

static
void	init_philo(t_philo *philo, t_fork **forks, t_args *params, int current)
{
	philo->params = params;
	philo->pos = current;
	philo->last_meal = 0;
	philo->meal_count = 0;
	philo->r_fork = &((*forks)[current]);
	philo->r_taken = 0;
	philo->l_taken = 0;
	if (current == params->num - 1)
		philo->l_fork = &((*forks)[0]);
	else
		philo->l_fork = &((*forks)[current + 1]);
	philo->l_fork->used = 0;
	pthread_mutex_init(&(philo->m_last_meal), NULL);
	pthread_mutex_init(&(philo->l_fork->lock), NULL);
}

int	create_philos(t_philo **philos, t_fork **forks, t_args	*params)
{
	int	position;

	*philos = malloc(sizeof(t_philo) * params->num);
	if (!(*philos))
		return (0);
	*forks = malloc(sizeof(t_fork) * params->num);
	if (!(*forks))
	{
		free(*philos);
		return (0);
	}
	position = 0;
	while (position < params->num)
	{
		init_philo(&(*philos)[position], forks, params, position);
		position++;
	}
	return (1);
}

int	init_args(t_args *params, int argc, char **argv)
{
	if (argc < 5)
	{
		printf("Invalid number of args");
		return (0);
	}
	params->num = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	params->meal_max = -1;
	if (argc > 5)
	{
		params->meal_max = ft_atoi(argv[5]);
		if (ft_atoi(argv[5]) <= 0)
			return (0);
	}
	params->is_dead = 0;
	if (params->num <= 0 || params->time_to_die < 0 || params->time_to_eat < 0
		|| params->time_to_sleep < 0)
		return (0);
	pthread_mutex_init(&(params->console_mutex), NULL);
	pthread_mutex_init(&(params->m_is_dead), NULL);
	return (1);
}
