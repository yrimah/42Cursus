/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:56:03 by yrimah            #+#    #+#             */
/*   Updated: 2022/11/10 12:11:14 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>

int		ft_print_char(int c);
void	ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_check_format(va_list args, const char format);
int		ft_printf(const char *str, ...);
int		ft_printp(unsigned long long addr);
int		ft_print_percent(void);
int		ft_print_numb(int number);
int		ft_printf_hexa(unsigned int n, const char format);
int		ft_printf_u(unsigned int n);
char	*ft_itoa(int i);

#endif
