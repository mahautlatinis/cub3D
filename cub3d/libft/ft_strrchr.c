/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:09:34 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 04:09:34 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	chr;

	i = ft_strlen(str);
	chr = (char)c;
	while (1)
	{
		if (str[i] == chr)
			return ((char *)str + i);
		if (!i)
			return (0);
		i--;
	}
}
