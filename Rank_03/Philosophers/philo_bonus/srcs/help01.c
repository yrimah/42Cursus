/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:49:11 by yrimah            #+#    #+#             */
/*   Updated: 2023/03/15 10:49:15 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosophers.h"

void	ft_usleep(long int milis_time)
{
	long int	start_time;

	start_time = 0;
	start_time = get_timestamp();
	while ((get_timestamp() - start_time) < milis_time)
		usleep(1000);
}

void	write_state(char *str, t_philo *philo)
{
	int	cur_time;

	cur_time = get_timestamp() - philo->params->start_time;
	sem_wait(philo->params->sem_console);
	printf("%09d %d %s\n", cur_time, philo->pos, str);
	sem_post(philo->params->sem_console);
}

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int	cur;
	int	num;
	int	sign;

	cur = 0;
	num = 0;
	sign = 1;
	while ((str[cur] >= 9 && str[cur] <= 13) || str[cur] == ' ')
		cur++;
	if (str[cur] == '+' || str[cur] == '-')
	{
		if (str[cur] == '-')
			sign = -1;
		cur++;
	}
	while (str[cur] >= '0' && str[cur] <= '9')
	{
		num = num * 10 + str[cur] - '0';
		cur++;
	}
	return (num * sign);
}
