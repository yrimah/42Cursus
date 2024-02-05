/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:17:59 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/19 12:35:49 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	counter1;
	size_t	counter2;
	size_t	i;

	i = len;
	if (len > ft_strlen(s))
		i = ft_strlen(s);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	sub = malloc((i + 1) * sizeof(char));
	if (!sub)
		return (0);
	counter1 = 0;
	counter2 = 0;
	while (s[counter1])
	{
		if (counter2 < len && counter1 >= start)
			sub[counter2++] = s[counter1];
		counter1++;
	}
	sub[counter2] = 0;
	return (sub);
}
