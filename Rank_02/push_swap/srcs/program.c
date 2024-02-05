/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:03:45 by yrimah            #+#    #+#             */
/*   Updated: 2023/01/08 13:03:50 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_args_1(t_program *ps, char *argv)
{
	int		i;
	char	**split;

	split = ft_split(argv, ' ');
	if (!split)
		exit(1);
	ps->argv = split;
	ps->filled = 1;
	i = -1;
	while (split[++i])
		;
	ps->argc = i;
}

int	ft_validate(t_program *ps)
{
	t_stack	*_new;
	int		i;

	if (!ps->argc || ps->argc == 1)
		exit(0);
	i = -1;
	while (++i < ps->argc)
		if (!ft_isint(ps->argv[i]))
			return (1);
	if (ft_isdup(ps->argv, ps->argc))
		return (1);
	ps->stack_a = NULL;
	i = -1;
	while (++i < ps->argc)
	{
		_new = ft_stacknew(ft_atoi(ps->argv[i]));
		if (!_new)
			return (ft_stackclear(&ps->stack_a));
		ft_stackadd_back(&ps->stack_a, _new);
	}
	ps->stack_b = NULL;
	ps->stack_a_size = ps->argc;
	ps->stack_b_size = 0;
	return (0);
}

void	push_swap(t_program *ps)
{
	if (ps->stack_a_size == 2)
		swap_a(ps, 1);
	else if (ps->stack_a_size == 3)
		ft_tiny_sort(ps);
	else
		ft_sort_stack(ps);
}
