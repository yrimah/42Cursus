/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:56:11 by yrimah            #+#    #+#             */
/*   Updated: 2022/11/10 12:04:17 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_print_numb(int number)
{
	char	*str;
	int		length;

	length = 0;
	str = ft_itoa(number);
	length = ft_putstr(str);
	free(str);
	return (length);
}
