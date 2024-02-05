/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:00:28 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/18 09:00:32 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*clst;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		clst = ft_lstlast(*lst);
		clst->next = new;
	}
}
