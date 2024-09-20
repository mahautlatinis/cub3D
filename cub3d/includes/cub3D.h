/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:55:53 by qdam              #+#    #+#             */
/*   Updated: 2023/10/03 21:57:16 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "libft.h"
# include "../../mlx_mac/mlx.h"
# include "cub3D_errors.h"

typedef struct s_cub_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	t_list	*raw_map;
}	t_cub_data;

// Deallocate a NULL-terminated array of strings
void	free_tab(char **tab);

// Display an error message then exit the program with exit code 1
void	error_then_exit(char *fname, char *msg);

/*	==== FILE HANDLER ==== */

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

/*	==== MAP HANDLER ==== */

// Allocate a square 2D char array from the raw map passed to argument
char	**make_char_map(t_list *raw_map);

// Check the map inside CUB file then returns an error message if any, else NULL
char	*check_cub_map(char **map);

void	rect(t_img *img, t_shape shape, int color);

#endif
