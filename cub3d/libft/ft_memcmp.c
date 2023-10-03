/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:21:20 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 19:21:20 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	t_uchar	*s1;
	t_uchar	*s2;
	size_t	i;

	s1 = (t_uchar *)b1;
	s2 = (t_uchar *)b2;
	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i])
			return ((int)(s1[i]) - (int)(s2[i]));
		i++;
	}
	return (0);
}
