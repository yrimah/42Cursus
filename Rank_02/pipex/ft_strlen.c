/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:15:56 by yrimah            #+#    #+#             */
/*   Updated: 2022/12/18 21:50:17 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/pipex.h"

int	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}
