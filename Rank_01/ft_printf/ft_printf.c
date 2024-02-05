/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:55:51 by yrimah            #+#    #+#             */
/*   Updated: 2022/11/10 10:55:56 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[counter])
		write(1, &str[counter++], 1);
	return (counter);
}

int	ft_check_format(va_list args, const char format)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter += ft_print_char(va_arg(args, int));
	else if (format == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		counter += ft_printp(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		counter += ft_print_numb(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		counter += ft_printf_hexa(va_arg(args, unsigned int), format);
	else if (format == 'u')
		counter += ft_printf_u(va_arg(args, unsigned int));
	else if (format == '%')
		counter += ft_print_percent();
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;
	int		len;

	len = 0;
	counter = 0;
	va_start(args, str);
	while (str[counter])
	{
		if (str[counter] == '%')
		{
			len += ft_check_format(args, str[counter + 1]);
			counter++;
		}
		else
			len += ft_print_char(str[counter]);
		counter++;
	}
	va_end(args);
	return (len);
}
