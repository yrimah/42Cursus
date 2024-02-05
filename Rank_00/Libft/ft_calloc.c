/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:58:35 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/10 08:58:40 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	if (size != 0 && ((n > SIZE_MAX / size)))
		return (NULL);
	p = malloc(n * size);
	if (!p)
		return (p);
	ft_bzero(p, n * size);
	return (p);
}
