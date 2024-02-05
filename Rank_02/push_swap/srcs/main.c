/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:03:39 by yrimah            #+#    #+#             */
/*   Updated: 2023/01/08 13:03:42 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

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

static void	ft_indexing(t_program *ps, size_t size)
{
	t_stack	*current;
	t_stack	*highest;
	int		stocked;

	while (--size)
	{
		highest = NULL;
		stocked = INT_MIN;
		current = ps->stack_a;
		while (current)
		{
			if (current->content == INT_MIN && current->index == DEF)
				current->index = 1;
			if (current->content > stocked && current->index == DEF)
			{
				stocked = current->content;
				highest = current;
				current = ps->stack_a;
			}
			else
				current = current->next;
		}
		if (highest)
			highest->index = size;
	}
}

static void	ft_free_stack(t_program *ps)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!ps->stack_a)
		return ;
	current = ps->stack_a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	ps->stack_a = NULL;
}

int	main(int argc, char **argv)
{
	t_program	main;

	main.filled = 0;
	if (argc == 2)
		ft_args_1(&main, argv[1]);
	if (!main.filled)
		ft_fill(&main, argc, argv);
	if (ft_validate(&main))
		ft_error("Error");
	if (ft_input_sorted(main.stack_a))
		return (0);
	ft_indexing(&main, main.stack_a_size + 1);
	push_swap(&main);
	if (main.filled)
		ft_free_main(&main);
	ft_free_stack(&main);
	return (0);
}
