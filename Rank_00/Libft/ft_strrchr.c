/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:59:13 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/19 12:18:27 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	counter;

	counter = ft_strlen(str);
	while (counter >= 0)
	{
		if (str[counter] == (char)c)
			return (((char *)str + counter));
		counter--;
	}
	return (0);
}
