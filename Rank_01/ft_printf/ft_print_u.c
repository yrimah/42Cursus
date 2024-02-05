/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:56:35 by yrimah            #+#    #+#             */
/*   Updated: 2022/11/10 11:50:24 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_itoa_u(unsigned int i)
{
	char	*final;
	int		length;

	length = ft_num_len(i);
	final = (char *)malloc(sizeof(char) * (length + 1));
	if (!final)
		return (0);
	final[length--] = '\0';
	while (i != 0)
	{
		final[length--] = '0' + (i % 10);
		i = i / 10;
	}
	return (final);
}

int	ft_printf_u(unsigned int n)
{
	char	*str;
	int		length;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	str = ft_itoa_u(n);
	length = ft_putstr(str);
	free(str);
	return (length);
}
