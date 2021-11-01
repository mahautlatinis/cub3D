/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:22:05 by qdam              #+#    #+#             */
/*   Updated: 2021/04/15 21:22:05 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_word(const char *word, char c)
{
	size_t	i;

	i = 0;
	while (word[i])
	{
		if (word[i] == c)
			break ;
		i++;
	}
	return (i);
}

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;
	int		seen_sep;

	i = 0;
	count = 0;
	seen_sep = 1;
	while (str[i])
	{
		if (str[i] == c)
			seen_sep = 1;
		else if (seen_sep)
		{
			count++;
			seen_sep = 0;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	w;
	size_t	i;

	if (!s)
		return (0);
	words = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	w = 0;
	i = 0;
	if (words)
	{
		while (s[i])
		{
			if (s[i] == c)
				i++;
			else
			{
				words[w] = ft_calloc(len_word(s + i, c) + 1, sizeof(char));
				ft_memcpy(words[w], s + i, len_word(s + i, c));
				w++;
				i += len_word(s + i, c);
			}
		}
	}
	return (words);
}
