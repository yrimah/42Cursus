/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:44:42 by yrimah            #+#    #+#             */
/*   Updated: 2023/01/08 16:44:44 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static int	ft_get_highest_index(t_stack *stack)
{
	t_stack	*current;
	int		highest;

	current = stack;
	highest = current->index;
	while (current)
	{
		if (current->index > highest)
			highest = current->index;
		current = current->next;
	}
	return (highest);
}

void	ft_tiny_sort(t_program *ps)
{
	int	highest;

	highest = ft_get_highest_index(ps->stack_a);
	if (ps->stack_a->index == highest)
		rotate_a(ps, 1);
	else if (ps->stack_a->next->index == highest)
		reverse_rotate_a(ps, 1);
	if (ps->stack_a->index > ps->stack_a->next->index)
		swap_a(ps, 1);
}
