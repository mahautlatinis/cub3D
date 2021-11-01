/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:55:53 by qdam              #+#    #+#             */
/*   Updated: 2021/10/09 01:03:58 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>

# include "libft.h"

# include "cub3D_errors.h"
# include "cub3D_defines.h"
# include "cub3D_game.h"
# include "cub3D_file_handlers.h"
# include "cub3D_graphics.h"
# include "cub3D_raycasting.h"

# ifdef __linux__
#  include "mlx_linux.h"
#  define USING_LINUX	1

# else
#  include "mlx_mac.h"
#  define USING_LINUX	0

int		mlx_destroy_display(void *mlx_ptr);

# endif

/*	==== MISC FUNCTIONS ==== */

// Return the size of an array of pointers
size_t	array_size(void **arr);

// Return the length of the longest string in the linked list
int		max_list_str_len(t_list *lst);

// Deallocate a NULL-terminated array of strings
void	free_tab(char **tab);

// Display an error message then exit the program with exit code 1
void	error_then_exit(char *fname, char *msg);

#endif
