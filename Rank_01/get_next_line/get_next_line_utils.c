/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:03:09 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/27 11:22:59 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	while (str[counter])
	{
		if (str[counter] == (char)c)
			return (((char *)str + counter));
		counter++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_new_line(char *str)
{
	char	*new;
	int		counter;

	counter = 0;
	if (!str[counter])
		return (NULL);
	while (str[counter] && str[counter] != '\n')
		counter++;
	new = malloc((counter + 2) * sizeof(char));
	if (!new)
		return (NULL);
	counter = 0;
	while (str[counter] && str[counter] != '\n')
	{
		new[counter] = str[counter];
		counter++;
	}
	if (str[counter] == '\n')
	{
		new[counter] = str[counter];
		counter++;
	}
	new[counter] = '\0';
	return (new);
}

char	*ft_mod_str(char *str)
{
	char	*new;
	int		counter1;
	int		counter2;

	counter1 = 0;
	counter2 = 0;
	while (str[counter1] && str[counter1] != '\n')
		counter1++;
	if (!str[counter1])
	{
		free(str);
		return (NULL);
	}
	new = malloc((ft_strlen(str) - counter1 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	counter1++;
	while (str[counter1])
		new[counter2++] = str[counter1++];
	new[counter2] = '\0';
	free(str);
	return (new);
}

char	*ft_strjoin(char *str, char *buf)
{
	char	*strj;
	size_t	counter1;
	size_t	counter2;

	counter1 = -1;
	counter2 = 0;
	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buf)
		return (0);
	strj = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1));
	if (!strj)
		return (0);
	if (str)
		while (str[++counter1])
			strj[counter1] = str[counter1];
	while (buf[counter2])
		strj[counter1++] = buf[counter2++];
	strj[ft_strlen(str) + ft_strlen(buf)] = '\0';
	free(str);
	return (strj);
}
