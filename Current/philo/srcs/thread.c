/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:26:43 by ariazano          #+#    #+#             */
/*   Updated: 2024/12/13 09:50:52 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_all(char *str, t_sim *sim, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&sim->write_lock);
	pthread_mutex_destroy(&sim->meals_lock);
	pthread_mutex_destroy(&sim->dead_lock);
	while (i < sim->philos[0].num_philos)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
}

int	death_mutex(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	create_thread(t_sim *sim, pthread_mutex_t *forks)
{
	pthread_t	status;
	int			i;

	if (pthread_create(&status, NULL, &check_status, sim->philos) != 0)
		destroy_all("thread create error", sim, forks);
	i = 0;
	while (i < sim->philos[0].num_philos)
	{
		if (pthread_create(&sim->philos[i].thread, NULL,
				&living, &sim->philos[i]) != 0)
			destroy_all("thread create error", sim, forks);
		i++;
	}
	i = 0;
	if (pthread_join(status, NULL) != 0)
		destroy_all("thread create error", sim, forks);
	while (i < sim->philos[0].num_philos)
	{
		if (pthread_join(sim->philos[i].thread, NULL) != 0)
			destroy_all("thread create error", sim, forks);
		i++;
	}
	return (0);
}
