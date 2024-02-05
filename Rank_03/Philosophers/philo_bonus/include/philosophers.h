/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:39:11 by yrimah            #+#    #+#             */
/*   Updated: 2023/03/14 19:39:16 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <semaphore.h>
# include <signal.h>
# include <pthread.h>
# include <time.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_args
{
	pthread_t	death_thread;
	int			num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meal_max;
	long		start_time;
	sem_t		*sem_console;
	sem_t		*sem_forks;
	sem_t		*finished;
}	t_args;

typedef struct s_philo
{
	pid_t		pid;
	int			pos;
	long		last_meal;
	sem_t		*sem_last_meal;
	int			meal_count;
	t_args		*params;
}	t_philo;

int		init_args(t_args *params, int argc, char **argv);
int		ft_atoi(const char *str);
int		create_philos(t_philo **philos, t_args	*params);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		create_process(t_philo **philos, t_args *params);
long	get_timestamp(void);
int		routine(t_philo *philo);
void	*check_death(void *arg);
void	ft_usleep(long int time_in_ms);
void	take_fork(t_philo *philo);
void	write_state(char *str, t_philo *philo);
void	release_forks_and_sleep(t_philo *philo);
void	*wait_death(void *arg);
int		stop_process(t_philo **philos, t_args *params);
int		wait_process(t_philo **philos, t_args *params);

#endif