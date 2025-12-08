/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleriaza <aleriaza@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:24:46 by ariazano          #+#    #+#             */
/*   Updated: 2025/12/04 01:39:07 by aleriaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

volatile sig_atomic_t		g_bit_check = 0;

void	confirm_bit(int signal)
{
	if (signal == SIGUSR1)
		g_bit_check = 1;
}

void	confirm_msg(int signal)
{
	if (signal == SIGUSR2)
		write(1, "showed\n", 7);
}

void	ft_atob(int pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_bit_check = 0;
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_bit_check)
			pause();
		bit++;
	}
}

void	setup_client_signals(struct sigaction *sa)
{
	sigemptyset(&sa->sa_mask);
	sa->sa_handler = confirm_bit;
	sigaddset(&sa->sa_mask, SIGUSR1);
	sa->sa_flags = SA_RESTART;
	sigaction(SIGUSR1, sa, NULL);
	sa->sa_handler = confirm_msg;
	sigaddset(&sa->sa_mask, SIGUSR2);
	sa->sa_flags = SA_RESTART;
	sigaction(SIGUSR2, sa, NULL);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		setup_client_signals(&sa);
		while (argv[2][i] != '\0')
			ft_atob(pid, (unsigned char)argv[2][i++]);
		ft_atob(pid, '\0');
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (EXIT_SUCCESS);
}
