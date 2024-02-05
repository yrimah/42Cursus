/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:02:23 by yrimah            #+#    #+#             */
/*   Updated: 2023/01/08 12:02:32 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/checker.h"

static void	ft_fill(t_program *ps, int argc, char **argv)
{
	ps->argc = argc - 1;
	ps->argv = argv + 1;
}

static void	ft_free_main(t_program *ps)
{
	int	i;

	i = -1;
	while (ps->argv[++i])
		free(ps->argv[i]);
	free(ps->argv);
}

int	main(int argc, char **argv)
{
	t_program	ps;
	char		*buf;

	ps.filled = 0;
	if (argc == 2)
		ft_args_1(&ps, argv[1]);
	if (!ps.filled)
		ft_fill(&ps, argc, argv);
	if (ft_validate(&ps))
		ft_error("Error");
	while (1)
	{
		buf = get_next_line(0);
		if (!buf || *buf == '\n')
		{
			free(buf);
			ft_stacksorted(&ps);
			if (ps.filled)
				ft_free_main(&ps);
			exit(0);
		}
		ft_do(&ps, buf);
		free(buf);
	}
}
