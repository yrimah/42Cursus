/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:34:42 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/10 12:52:16 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		counter;
	char		*nbptr;
	char		*nlptr;

	if (!*little)
		return ((char *)big);
	while (len-- && *big)
	{
		if (*big == *little)
		{
			counter = len;
			nbptr = (char *)big + 1;
			nlptr = (char *)little + 1;
			while (counter-- && *nbptr && *nlptr && *nlptr == *nbptr)
			{
				nlptr++;
				nbptr++;
			}
			if (*nlptr == '\0')
				return ((char *)big);
		}
		big++;
	}
	return (0);
}
