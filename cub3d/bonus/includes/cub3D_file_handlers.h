/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_file_handlers.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:15:09 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:29:22 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_FILE_HANDLERS_H
# define CUB3D_FILE_HANDLERS_H

# include "cub3D_structs.h"

bool	array_has_str(char *str, char **arr);
bool	can_read_file(char *fname);
bool	check_file_ext(char *fname, char *ext);
bool	str_has_charset(char *str, char *charset);
char	**make_char_map(t_list *raw_map);
char	*check_cub_map(char **map);
char	*parse_cub(t_cub_data *cub, int fd);
char	*skip_chars(char *str, char c);
void	free_cub_data(t_cub_data *cub);
void	init_cub_data(t_cub_data *cub);

#endif