/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:14:22 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 19:14:22 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	t_uchar	*str;
	size_t	i;

	str = (t_uchar *)b;
	i = 0;
	while (i < len)
	{
		if (str[i] == (t_uchar)c)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
