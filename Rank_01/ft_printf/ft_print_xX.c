/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:56:27 by yrimah            #+#    #+#             */
/*   Updated: 2022/11/10 10:56:31 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_hexa_len(unsigned int n)
{
	int	counter;

	counter = 0;
	while (n != 0)
	{
		counter++;
		n /= 16;
	}
	return (counter);
}

void	ft_hexa(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_hexa(n / 16, format);
		ft_hexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
			else if (format == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	ft_printf_hexa(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_hexa(n, format);
	return (ft_hexa_len(n));
}
