/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:02:34 by yrimah            #+#    #+#             */
/*   Updated: 2023/01/08 13:02:37 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	swap_a(t_program *ps, int display)
{
	if (ps->stack_a_size < 2)
		return (0);
	ft_stackadd_front(&ps->stack_a, ft_stackdup(*(ps->stack_a->next)));
	free(ps->stack_a->next->next);
	ps->stack_a->next->next = ps->stack_a->next->next->next;
	if (display)
		ft_putstr_fd("sa\n", 1);
	return (1);
}

int	swap_b(t_program *ps, int display)
{
	if (ps->stack_b_size < 2)
		return (0);
	ft_stackadd_front(&ps->stack_b, ft_stackdup(*(ps->stack_b->next)));
	free(ps->stack_b->next->next);
	ps->stack_b->next->next = ps->stack_b->next->next->next;
	if (display)
		ft_putstr_fd("sb\n", 1);
	return (1);
}

int	swap_ab(t_program *ps, int display)
{
	return (swap_a(ps, display) + swap_b(ps, display));
}
