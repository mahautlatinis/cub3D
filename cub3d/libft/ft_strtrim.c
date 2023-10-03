/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:42:57 by qdam              #+#    #+#             */
/*   Updated: 2021/04/15 20:42:57 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_string(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (str)
		str[0] = 0;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len_set;
	char	*str;

	if (!s1 || !set)
		return (0);
	if (ft_strlen(s1) == 0)
		return (empty_string());
	start = 0;
	end = ft_strlen(s1);
	len_set = ft_strlen(set);
	while (s1[start] && ft_memchr(set, s1[start], len_set))
		start++;
	while (end > start && ft_memchr(set, s1[end - 1], len_set))
		end--;
	str = malloc(end - start + 1);
	if (str)
	{
		ft_memcpy(str, s1 + start, end - start);
		str[end - start] = 0;
	}
	return (str);
}
