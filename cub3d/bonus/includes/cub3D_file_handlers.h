/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_file_handlers.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:15:09 by qdam              #+#    #+#             */
/*   Updated: 2021/09/08 15:29:18 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_FILE_HANDLERS_H
# define CUB3D_FILE_HANDLERS_H

# include "cub3D_structs.h"

// Skip all occurrences of c at the beginning of str and return the pointer
// to the first character of str which is not c
char	*skip_chars(char *str, char c);

// Return true if str contains any character in charset, false otherwise
bool	str_has_charset(char *str, char *charset);

// Return true if arr contains str, false otherwise
bool	array_has_str(char *str, char **arr);

// Return true if fname is a valid file name with extension ext, false otherwise
bool	check_file_ext(char *fname, char *ext);

// Return true if fname can be read and not empty, false otherwise
bool	can_read_file(char *fname);

// Initialize cub's members to default values
void	init_cub_data(t_cub_data *cub);

// Free all memories allocated in cub
void	free_cub_data(t_cub_data *cub);

// Parse cub data into the structure passed to argument. If any error occurs
// (read error, format error...) return the error message, otherwise NULL
char	*parse_cub(t_cub_data *cub, int fd);

// Allocate a square 2D char array from the raw map passed to argument
char	**make_char_map(t_list *raw_map);

// Check the map inside CUB file then returns an error message if any, else NULL
char	*check_cub_map(char **map);

#endif