/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:34:28 by ariazano          #+#    #+#             */
/*   Updated: 2024/11/07 23:37:31 by ariazano         ###   ########.fr       */
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
	int				philo;
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

typedef struct	s_main
{
	int				died;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meals_lock;
	pthread_mutex_t	write_lock;
	t_philo			philos;
}				t_main;

// main
void	av_check(int ac, char **av);

// utils
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	error_message(char *text, int signal);
int		ft_usleep(size_t ms);
size_t	get_current_time(void);

#endif