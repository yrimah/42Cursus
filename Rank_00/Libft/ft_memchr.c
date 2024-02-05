/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:59:25 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/10 08:59:32 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (size != 0)
	{
		if (*s == (unsigned char)c)
			return (s);
		s++;
		size--;
	}
	return (0);
}
