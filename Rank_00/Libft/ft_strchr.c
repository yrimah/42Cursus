/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:00:13 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/10 11:20:31 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	counter;

	counter = 0;
	while (counter <= ft_strlen(str))
	{
		if (str[counter] == (char)c)
			return (((char *)str + counter));
		counter++;
	}
	return (0);
}
