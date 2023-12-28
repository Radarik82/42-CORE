/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:52:00 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/04 16:13:41 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	arg_is_number(char *av)
{
	int	i;

	i = 1;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

int	symbol_handle(char **av)

{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 45 && j == 0)
				j++;
			if (ft_isdigit(av[i][j]) == 0)
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	int_handle(char **av)

{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	zero_handle(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[1][0] == '\0')
			return (1);
		if (av[i][0] == '0' && av[i][1])
			return (1);
		if (av[0][0] == '0' && av[0][1])
			return (1);
		else if (av[i][0] == '-' && av[i][1] == '0')
			return (1);
		i++;
	}
	return (0);
}
