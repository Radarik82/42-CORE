/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:35:32 by ariazano          #+#    #+#             */
/*   Updated: 2024/11/15 10:47:29 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	print_status(" is thinking...", philo, philo->id);
}

void	sleeping(t_philo *philo)
{
	print_status(" is sleeping___", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_r);
	print_status(" got a fork", philo, philo->id);
	if(philo->philos == 1)
	{
		ft_usleep(philo->time_to_die):
		pthread_mutex_unlock(philo->fork_r);
		return ;
	}
	pthread_mutex_lock(philo->fork_l);
	print_status(" got a fork", philo, philo->id);
	philo->eating = 1;
	print_status(" is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo_meals_last = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}