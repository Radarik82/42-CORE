/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:24:46 by ariazano          #+#    #+#             */
/*   Updated: 2023/11/19 01:39:07 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 0)
		{
			kill(info->si_pid, SIGUSR2);
		}
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa_newsig;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("SERVER PID = %d\n", pid);
	sa_newsig.sa_sigaction = &ft_btoa;
	sigemptyset(&sa_newsig.sa_mask);
	sa_newsig.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa_newsig, NULL);
		sigaction(SIGUSR2, &sa_newsig, NULL);
		pause ();
	}
	return (EXIT_SUCCESS);
}
