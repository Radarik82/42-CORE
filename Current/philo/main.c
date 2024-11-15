/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:33:13 by ariazano          #+#    #+#             */
/*   Updated: 2024/11/15 09:41:53 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	av_check(int ac, char **av)
{
	int		i;
	long	num;

	i = 0;
	if (ac != 5 || ac != 6)
		error_message("incorrect input\n", 1);
	while (i < ac)
	{
		i++;
		num = ft_atoi(av[i]);
		if (i == 1 && (num < 1 || num > PHILO_MAX))
			error_message("incorrect input\n", 1);
		else if (i == 5 && (num < 0 && num > INT_MAX))
			error_message("incorrect input\n", 1);
		else if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
			error_message("incorrect input\n", 1);
	}
}

int	main(int ac, char **av)
{
	t_sim			sim;
	t_philo			philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	
	av_check(ac, av);
	init_sim(&sim, philo);
	init_forks(forks, ft_atoi(av[1]));
	init_philo(philo, &sim, forks, av);
	threads_init(&sim, forks);
	threads_clean(NULL, &sim, forks);	
	return (0);
}
