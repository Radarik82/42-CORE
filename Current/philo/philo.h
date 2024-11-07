/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:34:28 by ariazano          #+#    #+#             */
/*   Updated: 2024/11/07 10:34:29 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define RESET    "\033[0m"
# define RED      "\033[31m"
# define GREEN    "\033[32m"

// typedef struct t_mutexes

// main
void	av_check(int ac, char **av);

// utils
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	error_message(char *text, int signal);

#endif