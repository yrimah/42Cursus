/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:00:30 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/10 09:00:34 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while (s1[counter] && s1[counter] == s2[counter] && n > 0)
	{
		counter++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
}
