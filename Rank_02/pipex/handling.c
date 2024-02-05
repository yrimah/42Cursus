/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:14:24 by yrimah            #+#    #+#             */
/*   Updated: 2022/12/18 21:14:29 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/pipex.h"

int	message(char *error)
{
	write(2, error, ft_strlen(error));
	return (EXIT_FAILURE);
}

void	error_message(char *error)
{
	perror(error);
	exit (EXIT_FAILURE);
}
