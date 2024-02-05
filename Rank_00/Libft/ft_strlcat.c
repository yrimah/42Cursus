/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:23:11 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/10 09:26:02 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter1;
	size_t	counter2;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	counter1 = ft_strlen(dst);
	counter2 = 0;
	while (src[counter2] != 0 && counter1 + 1 < dstsize)
	{
		dst[counter1] = src[counter2];
		counter1++;
		counter2++;
	}
	dst[counter1] = 0;
	return (ft_strlen(dst) + ft_strlen(&src[counter2]));
}
