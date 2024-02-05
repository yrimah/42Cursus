/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:16:07 by yrimah            #+#    #+#             */
/*   Updated: 2022/12/18 21:50:45 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

// write, read, close, access, pipe, dup2, execve, fork
# include <unistd.h>
# include <sys/types.h>

// malloc, free, exit
# include <stdlib.h>

// open
# include <fcntl.h>

// waitpid
# include <sys/wait.h>

// perror
# include <stdio.h>
//
# define ERR_INPUT "invalid number of arguments"
# define ERR_IN "input file"
# define ERR_OUT "output file"
# define ERR_CMD "command not found\n"
# define ERR_PIPE "pipe"
# define ERR_EXEC "Execve failed"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	int		pipes[2];
	char	*paths;
	char	*cmd;
	char	**cmd_paths;
	char	**cmd_args;
}t_pipex;

// handling
void	error_message(char *error);
int		message(char *error);

// processes
void	child_process1(t_pipex pipex, char **argv, char **envp);
void	child_process2(t_pipex pipex, char **argv, char **envp);

// free_processes
void	free_process_child(t_pipex *pipex);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
char	*get_path(char **argv, char **envp);
int		first_word(char *str);

#endif
