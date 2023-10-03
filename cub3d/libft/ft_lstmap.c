/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 04:16:08 by qdam              #+#    #+#             */
/*   Updated: 2021/04/17 04:16:08 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*alloc_list(int len, void (*del)(void *))
{
	int		i;
	t_list	*first;
	t_list	*cur;

	i = -1;
	first = 0;
	while (++i < len)
	{
		cur = ft_lstnew(0);
		if (!cur)
		{
			ft_lstclear(&first, del);
			return (0);
		}
		ft_lstadd_back(&first, cur);
	}
	return (first);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*current;

	if (!lst || !f)
		return (0);
	first = alloc_list(ft_lstsize(lst), del);
	if (first)
	{
		current = first;
		while (lst)
		{
			current->content = f(lst->content);
			current = current->next;
			lst = lst->next;
		}
	}
	return (first);
}
