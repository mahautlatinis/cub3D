/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 03:59:35 by qdam              #+#    #+#             */
/*   Updated: 2021/04/17 03:59:35 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *elem)
{
	t_list	*lst;

	if (!alst || !elem)
		return ;
	if (!(*alst))
		return (ft_lstadd_front(alst, elem));
	lst = *alst;
	while (lst->next)
		lst = lst->next;
	lst->next = elem;
}
