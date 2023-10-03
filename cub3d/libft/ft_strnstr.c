/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:33:07 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 16:33:07 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	len_tf;
	size_t	i;

	len_tf = ft_strlen(to_find);
	if (!len_tf)
		return ((char *)str);
	else if (len_tf > ft_strlen(str) || len_tf > n)
		return (0);
	i = 0;
	while (i <= n - len_tf)
	{
		if (!ft_strncmp(str + i, to_find, len_tf))
			return ((char *)str + i);
		i++;
	}
	return (0);
}
