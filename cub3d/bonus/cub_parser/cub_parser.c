/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 23:15:38 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:17:05 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*parse_cub_line_texture(t_cub_data *cub, char *line);
char	*parse_cub_line_color(t_cub_data *cub, char **tab);
char	*parse_cub_line_map(t_cub_data *cub, char *line);

static inline char	*parse_cub_line(t_cub_data *cub, char *line)
{
	char	**tab;
	char	*error;

	tab = ft_split(line, ' ');
	if (!tab)
		error = MALLOC_SPLIT;
	else if (!tab[0])
		error = NULL;
	else if (array_has_str(tab[0], (char *[]){"NO", "SO", "WE", "EA", NULL}))
		error = parse_cub_line_texture(cub, line);
	else if (array_has_str(tab[0], (char *[]){"F", "C", NULL}))
		error = parse_cub_line_color(cub, tab);
	else if (**tab == '1')
		error = parse_cub_line_map(cub, line);
	else
		error = PARSER_LINE_FMT;
	if (error)
		free_cub_data(cub);
	free_tab(tab);
	return (error);
}

char	*parse_cub(t_cub_data *cub, int fd)
{
	char	*line;
	char	*error;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		error = parse_cub_line(cub, line);
		free(line);
		if (error)
			return (error);
	}
	if (!check_file_ext(cub->no, ".xpm") || !check_file_ext(cub->so, ".xpm")
		|| !check_file_ext(cub->we, ".xpm") || !check_file_ext(cub->ea, ".xpm"))
		error = PARSER_XPM_EXT;
	else if (!can_read_file(cub->no) || !can_read_file(cub->so)
		|| !can_read_file(cub->we) || !can_read_file(cub->ea))
		error = PARSER_XPM_OPN;
	if (!error)
		error = check_cub_map(make_char_map(cub->raw_map));
	if (error)
		free_cub_data(cub);
	return (error);
}
