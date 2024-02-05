/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:56:41 by yrimah            #+#    #+#             */
/*   Updated: 2022/11/10 11:54:36 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_prt_len(unsigned long long addr)
{
	int	counter;

	counter = 0;
	while (addr)
	{
		addr /= 16;
		counter++;
	}
	return (counter);
}

void	ft_pptr(unsigned long long addr)
{
	if (addr >= 16)
	{
		ft_pptr(addr / 16);
		ft_pptr(addr % 16);
	}
	else
	{
		if (addr <= 9)
			ft_putchar(addr + '0');
		else
			ft_putchar(addr - 10 + 'a');
	}
}

int	ft_printp(unsigned long long addr)
{
	int	printed;

	printed = 0;
	if (addr == 0)
		return (write(1, "0x0", 3));
	printed += write(1, "0x", 2);
	printed += ft_prt_len(addr);
	ft_pptr(addr);
	return (printed);
}
