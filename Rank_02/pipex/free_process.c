/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:15:37 by yrimah            #+#    #+#             */
/*   Updated: 2022/12/26 16:34:12 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/pipex.h"

void	free_process_child(t_pipex *pipex)
{
	int	counter;

	counter = 0;
	while (pipex->cmd_args[counter])
	{
		free(pipex->cmd_args[counter]);
		counter++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}
