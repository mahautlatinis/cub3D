/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 23:03:46 by qdam              #+#    #+#             */
/*   Updated: 2021/04/15 23:03:46 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*int_min(void)
{
	char	*buf;

	buf = malloc(sizeof(char) * 12);
	if (buf)
	{
		ft_memcpy(buf, "-2147483648", 11);
		buf[11] = 0;
	}
	return (buf);
}

static size_t	count_digits(int n)
{
	size_t	count;
	size_t	neg;

	count = 0;
	neg = (n < 0);
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count + neg);
}

static void	put_nbr(int n, char *buf)
{
	if (n >= 10)
		put_nbr(n / 10, buf - 1);
	*buf = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*buf;

	if (n == -2147483648)
		return (int_min());
	len = count_digits(n);
	buf = malloc(sizeof(char) * (len + 1));
	if (buf)
	{
		if (n < 0)
		{
			n *= -1;
			buf[0] = '-';
		}
		buf[len] = 0;
		put_nbr(n, buf + len - 1);
	}
	return (buf);
}
