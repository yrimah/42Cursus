/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:58:59 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/10 10:05:20 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t size)
{
	unsigned char	*ptr;
	size_t			counter;

	ptr = s;
	counter = 0;
	while (counter++ < size)
		*ptr++ = 0;
}
