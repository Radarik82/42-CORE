/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:34:28 by ariazano          #+#    #+#             */
/*   Updated: 2024/11/25 09:00:24 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define RESET    "\033[0m"
# define RED      "\033[31m"
# define GREEN    "\033[32m"
# define PHILO_MAX 200

typedef struct	s_philo
{
	int				meals;
	int				meals_to_eat;
	int				meals_eaten;
	int				philos;
	int				id;
	int				eating;
	int				*dead;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_start;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meals_lock;
	pthread_mutex_t	*dead_lock;
	pthread_t		thread;
	size_t			meals_last;
}				t_philo;

typedef struct	s_sim
{
	int				died;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meals_lock;
	pthread_mutex_t	write_lock;
	t_philo			philos;
}				t_sim;

// main
void	av_check(int ac, char **av);

// utils
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	error_message(char *text, int signal);
int		ft_usleep(size_t ms);
size_t	get_current_time(void);

// thread
int	death_mutex(t_philo *philo);
int	create_thread(t_sim *sim, pthread_mutes_t *fork);

// mutex_status
void	print_status(char *str, t_philo *philo, int id);
int	philo_death(t_philo *philo, size_t time_to_die);
int	check_if_dead(t_philo *philo);
int	check_if_all_ate(t_philo *philo);
void	*check_status(void *flag);

// init
void	init_input(t_philo *philo, char **av);
void	init_philo(t_philo *philo; t_sim *sim, pthread_mutex_t *forks, char **av);
void	init_forks(pthread_mutex_t *forks, int philos);
void	init_sim(t_sim *sim, t_philo *philo);

// actions
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);
void	living(void *flag);

#endif