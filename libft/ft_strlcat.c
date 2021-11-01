/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:28:32 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 16:28:32 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (!size || size < len_d + 1)
		return (size + len_s);
	i = 0;
	while (src[i] && i < size - 1 - len_d)
	{
		dest[i + len_d] = src[i];
		i++;
	}
	dest[i + len_d] = 0;
	return (len_d + len_s);
}
