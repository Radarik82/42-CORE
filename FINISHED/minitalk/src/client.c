/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:21:16 by ariazano          #+#    #+#             */
/*   Updated: 2023/11/19 01:41:59 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

// static int	ft_atoi(const char *str)
// {
// 	int					i;
// 	int					sign;
// 	unsigned long int	result;

// 	i = 0;
// 	sign = 1;
// 	result = 0;
// 	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '-')
// 	{
// 		sign = -1;
// 		i++;
// 	}
// 	else if (str[i] == '+')
// 		i++;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result *= 10;
// 		result += str[i] - '0';
// 		i++;
// 	}
// 	return (result * sign);
// }

void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Receieved!\n");
}

void	config_signal(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_handler = &sig_handler;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
	{
		ft_printf("failed to change SIGUSR1\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
	{
		ft_printf("failed to change SIGUSR1\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	config_signal();
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_printf("Client PID == %d\n", pid);
		while (argv[2][i] != '\0')
		{
			ft_atob(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
