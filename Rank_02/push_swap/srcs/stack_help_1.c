/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_help_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:03:54 by yrimah            #+#    #+#             */
/*   Updated: 2023/01/08 13:03:56 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*tab;

	tab = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!tab)
		return (NULL);
	tab->content = content;
	tab->position = DEF;
	tab->target_position = DEF;
	tab->index = DEF;
	tab->cost_stack_a = DEF;
	tab->cost_stack_b = DEF;
	tab->next = NULL;
	return (tab);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current->next)
		current = current->next;
	return (current);
}

int	ft_stackclear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*help;

	if (!stack)
		return (1);
	current = (*stack);
	help = (*stack);
	while (current)
	{
		help = help->next;
		free(current);
		current = help;
	}
	*stack = NULL;
	return (1);
}

void	ft_stackadd_back(t_stack **stack, t_stack *_new)
{
	t_stack	*current;

	if (!stack || !_new)
		return ;
	current = (*stack);
	if (!current)
	{
		*stack = _new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = _new;
}

void	ft_stackadd_front(t_stack **stack, t_stack *_new)
{
	if (!_new)
		return ;
	if (!stack)
	{
		*stack = _new;
		return ;
	}
	_new->next = (*stack);
	(*stack) = _new;
}
