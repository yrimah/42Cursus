/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:33 by yrimah            #+#    #+#             */
/*   Updated: 2023/03/15 11:56:37 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosophers.h"

static void	init_philo(t_philo *phil, t_args *params, int current)
{
	char	*pos_str;
	char	*sem_name;

	phil->params = params;
	phil->pos = current;
	phil->last_meal = 0;
	phil->meal_count = 0;
	pos_str = ft_itoa(phil->pos);
	sem_name = ft_strjoin("/sem_last_meal", pos_str);
	sem_unlink(sem_name);
	phil->sem_last_meal = sem_open(sem_name, O_CREAT, 0644, 1);
	sem_unlink(sem_name);
	free(pos_str);
	free(sem_name);
}

int	create_philos(t_philo **philos, t_args	*params)
{
	int	current;

	*philos = malloc(sizeof(t_philo) * params->num);
	if (!(*philos))
		return (0);
	current = 0;
	while (current < params->num)
	{
		init_philo(&(*philos)[current], params, current);
		current++;
	}
	return (1);
}

static void	init_sem(t_args *params)
{
	sem_unlink("/sem_forks");
	sem_unlink("/sem_console");
	sem_unlink("/finished");
	params->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, params->num);
	params->sem_console = sem_open("/sem_console", O_CREAT, 0644, 1);
	params->finished = sem_open("/finished", O_CREAT, 0644, 1);
	sem_unlink("/sem_forks");
	sem_unlink("/sem_console");
	sem_unlink("/finished");
	sem_wait(params->finished);
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
	if (params->num <= 0 || params->time_to_die < 0 || params->time_to_eat < 0
		|| params->time_to_sleep < 0)
		return (0);
	init_sem(params);
	return (1);
}
