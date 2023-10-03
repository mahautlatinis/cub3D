/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:05:34 by qdam              #+#    #+#             */
/*   Updated: 2021/10/09 01:55:29 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static inline void
	draw_wall_we(t_game *game, t_ray *ray, int start_x, int start_y)
{
	t_img	*img;
	int		dx;
	int		dy;
	int		tx;
	int		ty;

	if (ray->wall_dir == WE)
		img = &game->we;
	else
		img = &game->ea;
	dy = -1;
	while (++dy < ray->draw_height)
	{
		tx = (int)((ray->end.y - floor(ray->end.y)) * (double)(img->w));
		ty = (int)(((double)dy / ray->wall_height
					+ (1.0 - (double)ray->draw_height / ray->wall_height) / 2.0)
				* img->h);
		dx = -1;
		while (++dx < WIN_X / N_RAYS)
			put_px(start_x + dx, start_y + dy, get_px(tx, ty, img), &game->scr);
	}
}

static inline void
	draw_wall_ns(t_game *game, t_ray *ray, int start_x, int start_y)
{
	t_img	*img;
	int		dx;
	int		dy;
	int		tx;
	int		ty;

	if (ray->wall_dir == NO)
		img = &game->no;
	else
		img = &game->so;
	dy = -1;
	while (++dy < ray->draw_height)
	{
		tx = (int)((ray->end.x - floor(ray->end.x)) * (double)(img->w));
		ty = (int)(((double)dy / ray->wall_height
					+ (1.0 - (double)ray->draw_height / ray->wall_height) / 2.0)
				* img->h);
		dx = -1;
		while (++dx < WIN_X / N_RAYS)
			put_px(start_x + dx, start_y + dy, get_px(tx, ty, img), &game->scr);
	}
}

static inline void
	draw_wall(t_game *game, t_ray *ray, int start_x, int start_y)
{
	if (ray->wall_dir == NO || ray->wall_dir == SO)
		draw_wall_ns(game, ray, start_x, start_y);
	else
		draw_wall_we(game, ray, start_x, start_y);
}

void	draw_screen(t_game *game, t_ray *rays)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < N_RAYS)
	{
		rays[i].wall_dist *= cos(game->p.dir - rays[i].angle_abs);
		rays[i].wall_height = (int)(WIN_Y / rays[i].wall_dist);
		rays[i].draw_height = rays[i].wall_height;
		if (rays[i].draw_height > WIN_Y)
			rays[i].draw_height = WIN_Y;
		y = -1;
		while (++y < (WIN_Y - rays[i].draw_height) / 2)
		{
			x = i * (WIN_X / N_RAYS) - 1;
			while (++x < (i + 1) * (WIN_X / N_RAYS))
			{
				put_px(x, y, game->cei, &game->scr);
				put_px(x, WIN_Y - 1 - y, game->flo, &game->scr);
			}
		}
		draw_wall(game, &rays[i], i * (WIN_X / N_RAYS), y);
	}
}
