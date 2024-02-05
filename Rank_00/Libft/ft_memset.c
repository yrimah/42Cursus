/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:00:03 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/10 09:58:01 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t size)
{
	char	*str;

	str = ptr;
	while (size--)
	{
		*str = (unsigned char)c;
		str++;
	}
	return (ptr);
}
