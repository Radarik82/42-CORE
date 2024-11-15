/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:33:35 by ariazano          #+#    #+#             */
/*   Updated: 2024/11/15 10:16:40 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(t_philo *philo, char **av)
{
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->philos = ft_atoi(av[1]);
	if(av[5])
		philo->meals_to_eat = ft_atoi(av[5]);
	else
		philo->meals_to_eat = -1;
}

void	init_philo(t_philo *philo; t_sim *sim, pthread_mutex_t *forks, char **av)
{
	int	i;

	i = 0;
	while(i < ft_atoi(av[1]))
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		init_input(&philo[i], av);
		philo[i].time_start = get_current_time();
		philo[i].meals_last = get_current_time();
		philo[i].write_lock = &sim->write_lock;
		philo[i].dead_lock = &sim->dead_lock;
		philo[i].meal_lock = &sim->meal_lock;
		philo[i].dead = &sim->died;
		philo[i].fork_l = &forks[i];
		if (i == 0)
			philo[i].fork_r = &forks[philo[i].philos - 1];
		else
			philo[i].fork_r = &forks[i - 1];
		i++;
	}
}



void	init_forks(pthread_mutex_t *forks, int philos)
{
	int	i;
	
	i = 0;
	while(i < philos)
		pthread_mutex_init(&forks[i++], NULL);
}



void	init_sim(t_sim *sim, t_philo *philo)
{
	sim->died = 0;
	sim->philos = philo;
	pthread_mutex_init(&sim->write_lock, NULL);
	pthread_mutex_init(&sim->dead_lock, NULL);
	pthread_mutex_init(&sim->meals_lock, NULL);
}