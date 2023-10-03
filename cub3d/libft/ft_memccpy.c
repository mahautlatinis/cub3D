/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:23:30 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 17:23:30 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	t_uchar	*d;
	t_uchar	*s;
	size_t	i;

	d = (t_uchar *)dst;
	s = (t_uchar *)src;
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		if (d[i++] == (t_uchar)c)
			return ((void *)(d + i));
	}
	return (0);
}
