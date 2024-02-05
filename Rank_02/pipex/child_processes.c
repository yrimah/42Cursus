/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:15:28 by yrimah            #+#    #+#             */
/*   Updated: 2022/12/26 16:17:42 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/pipex.h"

static char	*commands(char **paths, char *cmd)
{
	char	*help;
	char	*command;

	if (!access(cmd, X_OK))
		return (cmd);
	if (!paths)
		return (NULL);
	while (*paths)
	{
		help = ft_strjoin(*paths, "/");
		command = ft_strjoin(help, cmd);
		free(help);
		if (!access(command, X_OK))
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	child_process1(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.pipes[1], 1);
	close(pipex.pipes[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = commands(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_process_child(&pipex);
		message(ERR_CMD);
		exit(EXIT_FAILURE);
	}
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		error_message(ERR_EXEC);
}

void	child_process2(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.pipes[0], 0);
	close(pipex.pipes[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = commands(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_process_child(&pipex);
		message(ERR_CMD);
		exit(EXIT_FAILURE);
	}
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		error_message(ERR_EXEC);
}
