/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:05:45 by yrimah            #+#    #+#             */
/*   Updated: 2022/11/10 12:09:28 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	digit_count(int i)
{
	int		count;

	count = 0;
	if (i == 0)
		return (1);
	while (i)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

size_t	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		counter;

	dup = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	counter = 0;
	while (src[counter])
	{
		dup[counter] = src[counter];
		counter++;
	}
	dup[counter] = 0;
	return (dup);
}

char	*ft_itoa(int i)
{
	char	*final;
	int		length;

	length = digit_count(i);
	if (i == -2147483648)
		return (ft_strdup("-2147483648"));
	if (i < 0)
		length++;
	final = (char *)malloc(sizeof(char) * (length + 1));
	if (!final)
		return (0);
	if (i < 0)
	{
		final[0] = '-';
		i = i * (-1);
	}
	final[length--] = '\0';
	while (i > 9)
	{
		final[length--] = '0' + (i % 10);
		i = i / 10;
	}
	if (i <= 9 && i >= 0)
		final[length] = i + '0';
	return (final);
}
