/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 04:05:40 by qdam              #+#    #+#             */
/*   Updated: 2021/04/17 04:05:40 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	cur = *lst;
	while (cur)
	{
		tmp = cur;
		if (del)
			del(tmp->content);
		cur = tmp->next;
		free(tmp);
	}
	*lst = 0;
}
