/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:55:53 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:33:53 by mahautlatin      ###   ########.fr       */
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
#  include "../../../mlx_mac/mlx.h"
#  define USING_LINUX	0

int		mlx_destroy_display(void *mlx_ptr);

# endif

int		max_list_str_len(t_list *lst);
size_t	array_size(void **arr);
void	error_then_exit(char *fname, char *msg);
void	free_tab(char **tab);
void	rect(t_img *img, t_shape shape, int color);
void	draw_line(t_img *img, t_vector s, t_vector e, double angle);
void	circle(t_img *img, t_shape s, int color);
#endif
