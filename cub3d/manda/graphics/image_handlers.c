/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:39:54 by qdam              #+#    #+#             */
/*   Updated: 2021/10/09 01:55:29 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	make_image_from_xpm(void *mlx_ptr, t_img *img, char *xpm)
{
	if (!mlx_ptr || !img || !xpm)
		return ;
	img->img = mlx_xpm_file_to_image(mlx_ptr, xpm, &img->w, &img->h);
	if (img->img)
		img->addr = mlx_get_data_addr(img->img, &img->bpp,
				&img->line, &img->end);
}

void	make_image_blank(void *mlx_ptr, t_img *img, int w, int h)
{
	if (!mlx_ptr || !img || !w || !h)
		return ;
	img->img = mlx_new_image(mlx_ptr, w, h);
	if (img->img)
		img->addr = mlx_get_data_addr(img->img, &img->bpp,
				&img->line, &img->end);
	img->w = w;
	img->h = h;
}
