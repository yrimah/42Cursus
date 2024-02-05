/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:59:52 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/15 13:04:22 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;
	int				counter;

	if (!src && !dest && size)
		return (0);
	ptrs = (unsigned char *)src;
	ptrd = (unsigned char *)dest;
	counter = 0;
	while (size)
	{
		((unsigned char *)ptrd)[counter] = ((unsigned char *)ptrs)[counter];
		size--;
		counter++;
	}
	return (dest);
}
