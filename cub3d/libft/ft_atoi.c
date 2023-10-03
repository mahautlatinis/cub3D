/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:44:06 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 16:44:06 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_range(int n, int low, int high)
{
	return (low <= n && n <= high);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int	i;

	if (!str)
		return (0);
	sign = 1;
	num = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || in_range(str[i], 9, 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}
