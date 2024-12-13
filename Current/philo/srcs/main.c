/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:33:13 by ariazano          #+#    #+#             */
/*   Updated: 2024/12/13 09:54:35 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_spelling(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] < '0' || av[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	av_check(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		error_message("Wrong argument count\n", 1);
	if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1]) <= 0
		|| check_spelling(av[1]) == 1)
		error_message("Invalid philosophers number\n", 1);
	if (ft_atoi(av[2]) <= 0 || check_spelling(av[2]) == 1)
		error_message("Invalid time to die\n", 1);
	if (ft_atoi(av[3]) <= 0 || check_spelling(av[3]) == 1)
		error_message("Invalid time to eat\n", 1);
	if (ft_atoi(av[4]) <= 0 || check_spelling(av[4]) == 1)
		error_message("Invalid time to sleep\n", 1);
	if (av[5] && (ft_atoi(av[5]) < 0 || check_spelling(av[5]) == 1))
		error_message("Invalid number of times to eat\n", 1);
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
	create_thread(&sim, forks);
	destroy_all(NULL, &sim, forks);
	return (0);
}
