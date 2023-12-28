/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:24:32 by ariazano          #+#    #+#             */
/*   Updated: 2023/07/05 15:30:40 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *rest_of_line, char *buff)
{
	unsigned int	len;
	char			*str;

	if (!rest_of_line)
	{
		rest_of_line = (char *)malloc(1 * sizeof(char) + 1);
		if (!rest_of_line)
			return (NULL);
		rest_of_line[0] = '\0';
	}
	if (!rest_of_line || !buff)
		return (NULL);
	len = ft_strlen(rest_of_line) + ft_strlen(buff);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (free (rest_of_line), free(str), NULL);
	ft_strcpy(str, rest_of_line);
	len = ft_strlen(rest_of_line);
	ft_strcpy(&str[len], buff);
	return (free(rest_of_line), str);
}
