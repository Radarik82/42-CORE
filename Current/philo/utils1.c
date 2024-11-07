/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:33:52 by ariazano          #+#    #+#             */
/*   Updated: 2024/11/07 22:05:11 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] + '0');
		i++;
		if (num == INT_MAX)
			break ;
	}
	return (num * sign);
}

void	error_message(char *text, int signal)
{
	if (text)
		write(2, text, ft_strlen(text) + 1);
	exit(signal);
}

size_t	get_current_time(void)
{
	struct timeval	time;
	
	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return(time.tv_sec * 1000 + time.tv_sec / 1000);
}

int	ft_usleep(size_t ms)
{
	size_t	start;
	
	start = get_current_time();
	while ((get_current_time() - start) < ms)
		usleep(500);
	return(0);
}