/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:02:53 by qdam              #+#    #+#             */
/*   Updated: 2021/08/25 17:16:06 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static size_t	max_str_len(t_list *lst)
{
	t_list	*cur;
	size_t	max;
	size_t	len;

	cur = lst;
	max = 0;
	while (cur)
	{
		len = ft_strlen((char *)(cur->content));
		if (len > max)
			max = len;
		cur = cur->next;
	}
	return (max);
}

static bool	mid_row_valid(char **map, int row, char *dir)
{
	int			col;

	col = -1;
	while (map[row][++col])
	{
		if (col == 0 && ft_strchr("0NSWE", map[row][col]))
			return (false);
		if (ft_strchr("NSWE", map[row][col]))
		{
			if (*dir)
				return (false);
			*dir = map[row][col];
		}
		if (ft_strchr("0NSWE", map[row][col])
			&& (ft_strchr(" ", map[row][col + 1])
			|| ft_strchr(" ", map[row][col - 1])
			|| ft_strchr(" ", map[row + 1][col])
			|| ft_strchr(" ", map[row - 1][col])
			|| ft_strchr(" ", map[row - 1][col + 1])
			|| ft_strchr(" ", map[row - 1][col - 1])
			|| ft_strchr(" ", map[row + 1][col + 1])
			|| ft_strchr(" ", map[row + 1][col - 1])))
			return (false);
	}
	return (true);
}

char	*check_cub_map(char **map)
{
	int		size;
	char	dir;
	int		i;

	if (!map || !(*map))
		return (CUBMAP_NULL);
	size = 0;
	while (map[size])
		size++;
	dir = 0;
	i = -1;
	while (++i < size)
		if (((i == 0 || i == size - 1) && str_has_charset(map[i], "0NSWE"))
			|| !mid_row_valid(map, i, &dir))
			break ;
	free_tab(map);
	if (i != size)
		return (CUBMAP_ROW_INV);
	if (!dir)
		return (CUBMAP_DEF_DIR);
	return (NULL);
}

char	**make_char_map(t_list *raw_map)
{
	size_t	width;
	size_t	height;
	size_t	i;
	t_list	*cur;
	char	**map;

	width = max_str_len(raw_map);
	height = ft_lstsize(raw_map);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	i = 0;
	cur = raw_map;
	while (i < height)
	{
		map[i] = ft_calloc(width + 1, sizeof(char));
		if (!map[i])
		{
			free_tab(map);
			return (NULL);
		}
		ft_memcpy(map[i++], cur->content, ft_strlen((char *)cur->content));
		cur = cur->next;
	}
	return (map);
}
