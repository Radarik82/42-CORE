/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:10:06 by ariazano          #+#    #+#             */
/*   Updated: 2023/11/19 01:16:55 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>

typedef struct sigaction		t_sigaction;
extern volatile sig_atomic_t	g_bit_check;
int	ft_atoi(const char *str);
int	ft_printf(const char *format, ...);

#endif