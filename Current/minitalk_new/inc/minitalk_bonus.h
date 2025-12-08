/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:10:06 by ariazano          #+#    #+#             */
/*   Updated: 2023/11/19 01:17:18 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/libft.h"
# include <signal.h>

typedef struct sigaction		t_sigaction;
extern volatile sig_atomic_t	g_bit_check;
int		ft_atoi(const char *str);
int		ft_printf(const char *format, ...);
void	confirm_msg(int signal);

#endif