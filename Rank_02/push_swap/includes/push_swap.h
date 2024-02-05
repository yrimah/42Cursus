/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:02:58 by yrimah            #+#    #+#             */
/*   Updated: 2023/01/08 12:03:08 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

# define DEF -77

typedef struct s_stack
{
	int				content;
	int				position;
	int				target_position;
	int				index;
	int				cost_stack_a;
	int				cost_stack_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_program
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	stack_a_size;
	size_t	stack_b_size;
	int		filled;
	int		argc;
	char	**argv;
}	t_program;

struct s_find_move
{
	t_program	*ps;
	int			cost_stack_a;
	int			cost_stack_b;
};

void	ft_args_1(t_program *ps, char *argv);
int		ft_validate(t_program *ps);

void	push_swap(t_program *ps);

void	ft_tiny_sort(t_program *ps);

void	ft_sort_stack(t_program *ps);
void	ft_set_pos(t_stack *stack);
void	ft_set_target_pos(t_program *ps);
void	ft_exec_move(struct s_find_move ret);
void	ft_get_least_pos_by_ranking(t_stack *stack, int *least_pos);

int		swap_a(t_program *ps, int display);
int		swap_b(t_program *ps, int display);
int		swap_ab(t_program *ps, int display);
int		push_a(t_program *ps, int display);
int		push_b(t_program *ps, int display);
int		rotate_a(t_program *ps, int display);
int		rotate_b(t_program *ps, int display);
int		rotate_ab(t_program *ps, int display);
int		reverse_rotate_a(t_program *ps, int display);
int		reverse_rotate_b(t_program *ps, int display);
int		reverse_rotate_ab(t_program *ps, int display);

int		ft_isint(char *str);
int		ft_isdup(char **argvs, int argc);

void	ft_error(char *str);

t_stack	*ft_stacknew(int content);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stackdup(t_stack stack);
int		ft_stackclear(t_stack **stack);
void	ft_stackadd_front(t_stack **stack, t_stack *_new);
void	ft_stackadd_back(t_stack **stack, t_stack *_new);
int		ft_input_sorted(t_stack *stack);

#endif
