/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:12:48 by qdam              #+#    #+#             */
/*   Updated: 2021/04/15 19:12:48 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(src);
	dup = malloc(len + 1);
	if (dup)
		ft_memcpy(dup, src, len + 1);
	return (dup);
}
