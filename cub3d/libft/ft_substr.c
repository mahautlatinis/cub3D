/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:18:08 by qdam              #+#    #+#             */
/*   Updated: 2021/04/15 19:18:08 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	sz;
	char	*sub;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_calloc(1, 1));
	if (len_s - start >= len)
		sz = len;
	else
		sz = len_s - start;
	sub = malloc(sz + 1);
	if (sub)
	{
		ft_memcpy(sub, s + start, sz);
		sub[sz] = 0;
	}
	return (sub);
}
