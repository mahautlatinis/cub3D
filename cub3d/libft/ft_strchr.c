/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:02:12 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 04:02:12 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*s;
	size_t	i;

	s = (char *)str;
	i = 0;
	while (i <= ft_strlen(str))
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (0);
}
