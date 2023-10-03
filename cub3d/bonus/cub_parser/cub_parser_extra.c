/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:28:11 by qdam              #+#    #+#             */
/*   Updated: 2021/10/09 01:55:29 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static inline char	*apply_colors(t_cub_data *cub, char *cat, char **colors)
{
	int		*r;
	int		*g;
	int		*b;

	if ((*cat == 'F' && cub->f_r >= 0) || (*cat == 'C' && cub->c_r >= 0))
		return (PARSER_COLOR_ONCE);
	r = &cub->f_r;
	g = &cub->f_g;
	b = &cub->f_b;
	if (*cat == 'C')
	{
		r = &cub->c_r;
		g = &cub->c_g;
		b = &cub->c_b;
	}
	*r = ft_atoi(colors[0]);
	*g = ft_atoi(colors[1]);
	*b = ft_atoi(colors[2]);
	free_tab(colors);
	if (!ft_inrange(*r, 0, 256) || !ft_inrange(*g, 0, 256)
		|| !ft_inrange(*b, 0, 256))
		return (PARSER_COLOR_RANGE);
	return (NULL);
}

static inline bool	ready_to_parse_map(t_cub_data *cub)
{
	return (cub->no && cub->so && cub->we && cub->ea
		&& cub->f_r >= 0 && cub->f_g >= 0 && cub->f_b >= 0
		&& cub->c_r >= 0 && cub->c_g >= 0 && cub->c_b >= 0);
}

char	*parse_cub_line_texture(t_cub_data *cub, char *line)
{
	enum e_direction	dir;

	dir = NONE;
	line = skip_chars(line, ' ');
	if (!ft_strncmp(line, "NO", 2) && !cub->no)
		dir = NO;
	else if (!ft_strncmp(line, "SO", 2) && !cub->so)
		dir = SO;
	else if (!ft_strncmp(line, "WE", 2) && !cub->we)
		dir = WE;
	else if (!ft_strncmp(line, "EA", 2) && !cub->ea)
		dir = EA;
	line += 2;
	line = skip_chars(line, ' ');
	if (*line == 0 || dir == NONE)
		return (PARSER_TEXTURE_LINE);
	if (dir == NO)
		cub->no = ft_strdup(line);
	else if (dir == SO)
		cub->so = ft_strdup(line);
	else if (dir == WE)
		cub->we = ft_strdup(line);
	else if (dir == EA)
		cub->ea = ft_strdup(line);
	return (NULL);
}

char	*parse_cub_line_color(t_cub_data *cub, char **tab)
{
	char	**colors;
	int		i;
	int		comma;

	if (!tab[1] || tab[2])
		return (PARSER_COLOR_LINE_ELEM);
	i = -1;
	comma = 0;
	while (tab[1][++i])
	{
		if (tab[1][i] == ',')
			++comma;
		else if (!ft_isdigit(tab[1][i]))
			return (PARSER_COLOR_LINE_CHAR);
	}
	if (comma != 2 || ft_strlen(tab[1]) > 11)
		return (PARSER_COLOR_LINE_FMT);
	colors = ft_split(tab[1], ',');
	if (!colors)
		return (MALLOC_COLLINE);
	return (apply_colors(cub, tab[0], colors));
}

char	*parse_cub_line_map(t_cub_data *cub, char *line)
{
	int		i;
	char	*content;
	t_list	*elem;

	if (!ready_to_parse_map(cub))
		return (PARSER_MAP_NOT_RDY);
	i = -1;
	while (line[++i])
		if (!ft_strchr("01 NSWE", line[i]))
			return (PARSER_MAP_CHAR);
	content = ft_strdup(line);
	if (!content)
		return (MALLOC_STRDUP);
	elem = ft_lstnew(content);
	if (!elem)
	{
		free(content);
		return (MALLOC_LSTNEW);
	}
	ft_lstadd_back(&cub->raw_map, elem);
	return (NULL);
}
