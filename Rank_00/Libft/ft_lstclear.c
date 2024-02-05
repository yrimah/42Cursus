/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:00:51 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/18 09:00:54 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_lst;

	if (*lst)
	{
		while (*lst)
		{
			to_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = to_lst;
		}
		*lst = 0;
	}
}
