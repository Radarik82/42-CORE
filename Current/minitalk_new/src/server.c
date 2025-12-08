/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleriaza <aleriaza@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:24:46 by ariazano          #+#    #+#             */
/*   Updated: 2025/12/08 16:08:38 by aleriaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	i = 0;

	(void)context;
	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	kill(info->si_pid, SIGUSR1);
	if (bit == 8)
	{
		if (i)
			ft_printf("%c", i);
		
		bit = 0;
		i = 0;
	}
}

void	setup_signals(struct sigaction *sa)
{
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sigaddset(&sa->sa_mask, SIGUSR2);
	sa->sa_flags = SA_SIGINFO | SA_RESTART;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("nothing sent\n");
		return (1);
	}
	pid = getpid();
	ft_printf("SERVER PID = %d\n", pid);
	sa.sa_sigaction = &ft_btoa;
	setup_signals(&sa);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause ();
	return (EXIT_SUCCESS);
}
