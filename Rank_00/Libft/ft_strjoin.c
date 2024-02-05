/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:12:35 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/12 09:16:40 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;
	int		counter;
	int		size;

	counter = 0;
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	strj = (char *)malloc(sizeof(char) * (size + 1));
	if (!strj)
		return (0);
	while (*s1)
		strj[counter++] = *s1++;
	while (*s2)
		strj[counter++] = *s2++;
	strj[counter] = '\0';
	return (strj);
}
