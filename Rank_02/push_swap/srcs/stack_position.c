/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:44:51 by yrimah            #+#    #+#             */
/*   Updated: 2023/01/08 16:44:54 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/checker.h"

static int	ft_get_target(t_program *ps, int stack_b_rank,
						int closest_rank, int target_position)
{
	t_stack	*crt;

	crt = ps->stack_a;
	while (crt)
	{
		if (crt->index > stack_b_rank && crt->index < closest_rank)
		{
			closest_rank = crt->index;
			target_position = crt->position;
		}
		crt = crt->next;
	}
	if (closest_rank != INT_MAX)
		return (target_position);
	crt = ps->stack_a;
	while (crt)
	{
		if (crt->index < closest_rank)
		{
			closest_rank = crt->index;
			target_position = crt->position;
		}
		crt = crt->next;
	}
	return (target_position);
}

void	ft_set_pos(t_stack *stack)
{
	t_stack	*current;
	int		i;

	i = -1;
	current = stack;
	while (current)
	{
		current->position = ++i;
		current = current->next;
	}
}

void	ft_set_target_pos(t_program *ps)
{
	t_stack	*current;
	int		target_position;

	current = ps->stack_b;
	ft_set_pos(ps->stack_a);
	ft_set_pos(ps->stack_b);
	target_position = 0;
	while (current)
	{
		target_position = ft_get_target(ps, current->index,
				INT_MAX, target_position);
		current->target_position = target_position;
		current = current->next;
	}
}

void	ft_get_least_pos_by_ranking(t_stack *stack, int *least_position)
{
	t_stack	*current;
	int		least_rank;

	least_rank = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->index < least_rank)
		{
			*least_position = current->position;
			least_rank = current->index;
		}
		current = current->next;
	}
}
