/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:02:41 by yrimah            #+#    #+#             */
/*   Updated: 2023/01/08 13:02:44 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	push_a(t_program *ps, int display)
{
	t_stack	*next;

	if (ps->stack_b_size < 1)
		return (0);
	next = ps->stack_b->next;
	ft_stackadd_front(&ps->stack_a, ps->stack_b);
	ps->stack_b = next;
	ps->stack_a_size++;
	ps->stack_b_size--;
	if (display)
		ft_putstr_fd("pa\n", 1);
	return (1);
}

int	push_b(t_program *ps, int display)
{
	t_stack	*next;

	if (ps->stack_a_size < 1)
		return (0);
	next = ps->stack_a->next;
	ft_stackadd_front(&ps->stack_b, ps->stack_a);
	ps->stack_a = next;
	ps->stack_a_size--;
	ps->stack_b_size++;
	if (display)
		ft_putstr_fd("pb\n", 1);
	return (1);
}

int	rotate_ab(t_program *ps, int display)
{
	return (rotate_a(ps, display) + rotate_b(ps, display));
}

int	reverse_rotate_ab(t_program *ps, int display)
{
	return (reverse_rotate_a(ps, display) + reverse_rotate_b(ps, display));
}
