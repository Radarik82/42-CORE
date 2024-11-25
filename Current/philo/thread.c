/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:26:43 by ariazano          #+#    #+#             */
/*   Updated: 2024/11/25 08:56:03 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_mutex(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if(*philo->dead == 1)
		return(pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return(0);
}

int	create_thread(t_sim *sim, pthread_mutes_t *fork)
{
	pthread_t	status;
	int			i;

	if(pthread_create(&status, NULL, &check_status, sim->philos) != 0)
		cleanall("thread creat error", sim, fork);
	i = 0;
	while(i < sim->philos[0].philos)
	{
		if(pthread_create(&sim->philos[i].thread, NULL, &living, sim->philos[i]) != 0)
			cleanall("thread creat error", sim, fork);
		i++;
	}
	i = 0;
	if(pthread_join(status, NULL) != 0)
		cleanall("thread creat error", sim, fork);
	while(i < sim->philos[0].philos)
	{
		if(pthread_join(sim->philos[i].thread, NULL) != 0)
			cleanall("thread creat error", sim, fork);
		i++;
	}
	return (0);
}
