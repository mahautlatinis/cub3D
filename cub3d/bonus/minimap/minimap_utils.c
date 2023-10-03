/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:06:45 by malatini          #+#    #+#             */
/*   Updated: 2021/10/09 02:14:54 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
** Permet d'afficher des rectangle (pour la minimap)
* @author: malatini
*/
void	rect(t_img *img, t_shape shape, int color)
{
	int	i;
	int	j;

	i = shape.y;
	while (i < shape.y + shape.height && i < img->w)
	{
		j = shape.x;
		while (j < shape.x + shape.width && j < img->h)
		{
			put_px(i, j, color, img);
			++j;
		}
		++i;
	}
}

/*
** Permet de tracer une ligne, va servir pour le raycast sur la minimap
* @author: malatini
*/
void	draw_line(t_img *img, t_vector s, t_vector e, double angle)
{
	double	deltax;
	double	deltay;
	int		pixels;

	deltax = cos(angle);
	deltay = sin(angle);
	pixels = round(sqrt(pow(s.x - e.x, 2) + pow(s.y - e.y, 2))) + 2;
	while (pixels && s.x > 0 && s.y > 0 && s.x < img->w && s.y < img->h)
	{
		put_px((int)s.x, (int)s.y, 0xD5A576, img);
		s.x += deltax;
		s.y += deltay;
		--pixels;
	}
}

/*
** Permet de dessiner un cercle sur l'image
* @author: malatini
*/
void	circle(t_img *img, t_shape s, int color)
{
	int		i;
	int		j;
	double	dist;

	i = s.y;
	while (i < s.y + s.height && i < img->w)
	{
		j = s.x;
		while (j < s.x + s.width && j < img->h)
		{
			dist = sqrt(pow(i - (s.y + s.height / 2), 2)
					+ pow(j - (s.x + s.width / 2), 2));
			if (dist < s.width / 2.0)
				put_px(i, j, color, img);
			++j;
		}
		++i;
	}
}
