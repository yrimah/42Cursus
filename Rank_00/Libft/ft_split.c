/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:10:24 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/12 09:12:10 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*w_dup(const char *str, int beg, int end)
{
	char	*word;
	int		counter;

	counter = 0;
	word = malloc((end - beg + 1) * sizeof(char));
	if (!word)
		return (0);
	while (beg < end)
		word[counter++] = str[beg++];
	word[counter] = '\0';
	return (word);
}

static int	w_count(const char *str, char c)
{
	int	counter;
	int	help;

	counter = 0;
	help = 0;
	while (*str)
	{
		if (*str != c && help == 0)
		{
			help = 1;
			counter++;
		}
		else if (*str == c)
			help = 0;
		str++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	size_t	counter1;
	size_t	counter2;
	int		index;
	char	**strs;

	strs = malloc((w_count(s, c) + 1) * sizeof(char *));
	if (!s || !strs)
		return (0);
	counter1 = -1;
	counter2 = 0;
	index = -1;
	while (++counter1 <= ft_strlen(s))
	{
		if (s[counter1] != c && index < 0)
			index = counter1;
		else if ((s[counter1] == c || counter1 == ft_strlen(s)) && index >= 0)
		{
			strs[counter2++] = w_dup(s, index, counter1);
			if (!strs[counter2])
				free(strs);
			index = -1;
		}
	}
	strs[counter2] = 0;
	return (strs);
}
