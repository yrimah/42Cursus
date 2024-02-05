/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:15:19 by yrimah            #+#    #+#             */
/*   Updated: 2022/12/26 16:31:24 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/pipex.h"

int	first_word(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	i = 0;
	while (str[i] <= 32 && str[i])
		i++;
	j = 0;
	k = i;
	while (str[i] && str[i] > 32)
	{
		j++;
		i++;
	}
	s = malloc((sizeof(char) * j) + 1);
	if (!s)
		return (0);
	i = 0;
	while (str[k] && str[k] > 32)
		s[i++] = str[k++];
	s[i] = '\0';
	i = access(s, X_OK);
	free(s);
	return (i);
}

char	*get_path(char **argv, char **envp)
{
	if (!ft_strncmp("PATH=", envp[6], 5))
		return (envp[6] + 5);
	if ((!first_word(argv[2]) && !first_word(argv[3])) || !first_word(argv[3]))
		return (NULL);
	if (access(argv[2], X_OK))
		write(1, "command not found\n", 19);
	if (access(argv[3], X_OK))
		write(1, "command not found\n", 19);
	exit(127);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipes[0]);
	close(pipex->pipes[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (message(ERR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.infile < 0)
		error_message(ERR_IN);
	if (pipex.outfile < 0)
		error_message(ERR_OUT);
	if (pipe(pipex.pipes) < 0)
		error_message(ERR_PIPE);
	pipex.paths = get_path(argv, envp);
	if (pipex.paths)
		pipex.cmd_paths = ft_split(pipex.paths, ':');
	else
		pipex.cmd_paths = NULL;
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		child_process1(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		child_process2(pipex, argv, envp);
	close_pipes(&pipex);
	return (EXIT_SUCCESS);
}
