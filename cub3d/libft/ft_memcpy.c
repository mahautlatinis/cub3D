/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:17:09 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 17:17:09 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	if (dst != (void *)src)
	{
		d = (char *)dst;
		s = (char *)src;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
