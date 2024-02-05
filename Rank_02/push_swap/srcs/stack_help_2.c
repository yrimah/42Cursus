/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_help_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:04:03 by yrimah            #+#    #+#             */
/*   Updated: 2023/01/08 13:04:06 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_input_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack	*ft_stackdup(t_stack stack)
{
	t_stack	*tab;

	tab = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!tab)
		return (NULL);
	tab->content = stack.content;
	tab->position = stack.position;
	tab->target_position = stack.target_position;
	tab->index = stack.index;
	tab->cost_stack_a = stack.cost_stack_a;
	tab->cost_stack_b = stack.cost_stack_b;
	tab->next = NULL;
	return (tab);
}
