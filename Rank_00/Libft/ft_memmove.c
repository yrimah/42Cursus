/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:55:16 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/15 13:04:47 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	counter;
	char	*ptrd;
	char	*ptrs;

	if (!src && !dest && size)
		return (0);
	if (size == 0)
		return (dest);
	counter = 0;
	ptrs = (char *)src;
	ptrd = (char *)dest;
	if (ptrd > ptrs)
		while (size-- > 0)
			ptrd[size] = ptrs[size];
	else
	{
		while (counter < size)
		{
			ptrd[counter] = ptrs[counter];
			counter++;
		}
	}
	return (dest);
}
