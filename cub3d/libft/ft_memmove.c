/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:40:49 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 18:40:49 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overlap(char *p1, char *p2, size_t len)
{
	if (p1 < p2 && p1 + len > p2)
		return (-1);
	else if (p2 < p1 && p2 + len > p1)
		return (1);
	return (0);
}

static void	revcpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = len - 1;
	while (i > 0)
	{
		dst[i] = src[i];
		i--;
	}
	dst[i] = src[i];
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	if (dst != (void *)src)
	{
		d = (char *)dst;
		s = (char *)src;
		if (overlap(d, s, len) == 1)
			revcpy(d, s, len);
		else
			ft_memcpy(dst, src, len);
	}
	return (dst);
}
