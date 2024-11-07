/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:33:13 by ariazano          #+#    #+#             */
/*   Updated: 2024/11/07 10:37:45 by ariazano         ###   ########.fr       */
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
	av_check(ac, av);
	
	return (0);
}
