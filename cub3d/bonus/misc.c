/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:24:36 by qdam              #+#    #+#             */
/*   Updated: 2023/10/03 22:15:38 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

size_t	array_size(void **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	max_list_str_len(t_list *lst)
{
	t_list	*cur;
	int		max;
	int		len;

	cur = lst;
	max = 0;
	while (cur)
	{
		len = (int)ft_strlen((char *)(cur->content));
		if (len > max)
			max = len;
		cur = cur->next;
	}
	return (max);
}

void	free_tab(char **tab)
{
	size_t	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	error_then_exit(char *fname, char *msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (fname)
	{
		ft_putstr_fd(fname, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	else
		ft_putstr_fd(UNKN_ERROR, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(0);
}
