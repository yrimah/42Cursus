/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:28:44 by yrimah            #+#    #+#             */
/*   Updated: 2023/03/14 18:28:48 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_args
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_max;
	int				num;
	long			start_time;
	pthread_mutex_t	console_mutex;
	int				is_dead;
	pthread_mutex_t	m_is_dead;
	pthread_t		death_thread;
}	t_args;

typedef struct s_fork
{
	int				used;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				pos;
	long			last_meal;
	pthread_mutex_t	m_last_meal;
	int				meal_count;
	t_fork			*r_fork;
	int				r_taken;
	t_fork			*l_fork;
	int				l_taken;
	t_args			*params;
}	t_philo;

int		init_args(t_args *params, int argc, char **argv);
int		ft_atoi(const char *str);
int		create_philos(t_philo **philos, t_fork **forks, t_args	*params);
int		create_threads(t_philo **philos, t_args *params);
long	get_timestamp(void);
void	*routine(void *arg);
void	ft_usleep(long int time_in_ms);
int		is_dead(t_philo *phil);
void	take_fork(char fork_name, t_philo *phil);
void	write_state(char *str, t_philo *phil);
void	release_forks_and_sleep(t_philo *phil);
void	release_fork(char fork_name, t_philo *phil);
void	*check_death(void *arg);
int		wait_threads(t_philo **philos, t_args *params);
int		stop_threads(t_philo *phil);

#endif
