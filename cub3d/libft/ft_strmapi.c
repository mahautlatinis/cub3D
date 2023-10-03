/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 23:37:33 by qdam              #+#    #+#             */
/*   Updated: 2021/04/15 23:37:33 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	i = 0;
	str = ft_calloc(1, len + 1);
	if (str)
	{
		while (i < len)
		{
			str[i] = f((unsigned int)i, s[i]);
			i++;
		}
	}
	return (str);
}
