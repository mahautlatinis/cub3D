/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:58:10 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 16:58:10 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	char	*mem;
	char	ch;
	size_t	i;

	mem = (char *)dest;
	ch = (char)c;
	i = 0;
	while (i < len)
	{
		mem[i] = ch;
		i++;
	}
	return (dest);
}
