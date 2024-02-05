/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:01:36 by yrimah            #+#    #+#             */
/*   Updated: 2022/10/18 09:01:39 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*to;
	t_list	*help;

	if (!lst || !f)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	to = new;
	lst = lst->next;
	while (lst)
	{
		help = ft_lstnew(f(lst->content));
		if (!help)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		to->next = help;
		to = help;
		lst = lst->next;
	}
	return (new);
}
