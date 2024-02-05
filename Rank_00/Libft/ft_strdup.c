/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:00:20 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/10 11:10:59 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		counter;

	dup = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	counter = 0;
	while (src[counter])
	{
		dup[counter] = src[counter];
		counter++;
	}
	dup[counter] = 0;
	return (dup);
}
