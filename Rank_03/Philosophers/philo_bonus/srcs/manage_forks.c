/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:51 by yrimah            #+#    #+#             */
/*   Updated: 2023/03/15 11:56:55 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosophers.h"

void	take_fork(t_philo *philo)
{
	sem_wait(philo->params->sem_forks);
	write_state("has taken a fork", philo);
}

void	release_forks_and_sleep(t_philo *philo)
{
	sem_post(philo->params->sem_forks);
	sem_post(philo->params->sem_forks);
	write_state("is sleeping", philo);
	ft_usleep(philo->params->time_to_sleep);
}
