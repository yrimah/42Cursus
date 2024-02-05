/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:47:59 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/15 13:06:21 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	counter;

	counter = 0;
	if (size > 0)
	{
		while (src[counter] && counter < (size - 1))
		{
			dest[counter] = src[counter];
			counter++;
		}
		dest[counter] = 0;
	}
	while (src[counter])
		counter++;
	return (counter);
}
