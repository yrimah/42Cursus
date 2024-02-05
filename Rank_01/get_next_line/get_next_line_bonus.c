/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:03:20 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/31 10:56:32 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_read_and_save(int fd, char *str)
{
	char	*buf;
	int		red_b;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	red_b = 1;
	while (red_b != 0 && !ft_strchr(str, '\n'))
	{
		red_b = read(fd, buf, BUFFER_SIZE);
		if (red_b == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[red_b] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[2048];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_and_save(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_new_line(str[fd]);
	str[fd] = ft_mod_str(str[fd]);
	return (line);
}
