/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:55:03 by malatini          #+#    #+#             */
/*   Updated: 2021/10/09 02:15:13 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	rect(t_img *img, t_shape shape, int color);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	draw_line(t_img *img, t_vector s, t_vector e, double angle);
void	circle(t_img *img, t_shape s, int color);

/*
** Dessine le sol (beige clair) de la minimap
* @author: malatini
*/
static inline void
	draw_minimap_floor(t_game *game, int sx, int sy, t_shape shape)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	shape.width = MINISIDE;
	shape.height = MINISIDE;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			shape.x = y * MINISIDE + sx;
			shape.y = x * MINISIDE + sy;
			if (game->map[y][x] && game->map[y][x] == '0')
				rect(&game->scr, shape, SAND);
			x++;
		}
		y++;
	}
}

/*
** Va permettre de dessiner tous les rayons du raycasting sur la minimap
* @author: malatini
*/
static inline void	draw_mini_raycast(t_game *g, t_ray *rays, int sx, int sy)
{
	t_vector	render;
	t_vector	renderend;
	int			j;

	render.x = g->p.pos.x * MINISIDE + sy;
	render.y = g->p.pos.y * MINISIDE + sx;
	j = 0;
	while (j < N_RAYS)
	{
		renderend.x = rays[j].end.x * MINISIDE + sy;
		renderend.y = rays[j].end.y * MINISIDE + sx;
		draw_line(&g->scr, render, renderend, rays[j].angle_abs);
		j++;
	}
}

/*
** Permet d'afficher les murs de la minimap
* @author: malatini
*/
static inline void
	draw_walls_minimap(t_game *game, int sx, int sy, t_shape shape)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			shape.x = y * MINISIDE + sx + 6;
			shape.y = x * MINISIDE + sy;
			if (game->map[y][x] && game->map[y][x] == '1')
				rect(&game->scr, shape, CHOCO);
			shape.x = y * MINISIDE + sx;
			shape.y = x * MINISIDE + sy;
			if (game->map[y][x] && game->map[y][x] == '1')
				rect(&game->scr, shape, BROWN);
			x++;
		}
		y++;
	}
}

/*
** Va permettre d'afficher le player sur la minimap (rond rouge avec contour)
* @author: malatini
*/
static inline void
	draw_player_minimap(t_game *game, t_shape s, int sx, int sy)
{
	s.width = 8;
	s.height = s.width;
	s.x = (int)(game->p.pos.y * MINISIDE + sx - s.width / 2);
	s.y = (int)(game->p.pos.x * MINISIDE + sy - s.height / 2);
	circle(&game->scr, s, RED);
	s.width = 6;
	s.height = s.width;
	s.x = (int)(game->p.pos.y * MINISIDE + sx - s.width / 2);
	s.y = (int)(game->p.pos.x * MINISIDE + sy - s.height / 2);
	circle(&game->scr, s, 0xF97A6D);
}

/*
** Permet de dessiner la minimap (a jour) sur l'image
* @author: malatini
*/
void	draw_minimap(t_game *game, t_ray *rays)
{
	t_shape	shape;
	int		starty;
	int		startx;

	if (!game->minimap_drawable)
		return ;
	shape.x = 0;
	shape.width = MINISIDE;
	shape.height = MINISIDE;
	starty = game->scr.w - (game->map_w * MINISIDE + MINIPAD);
	startx = game->scr.h - (game->map_h * MINISIDE + MINIPAD + 6);
	draw_minimap_floor(game, startx, starty, shape);
	draw_mini_raycast(game, rays, startx, starty);
	draw_walls_minimap(game, startx, starty, shape);
	draw_player_minimap(game, shape, startx, starty);
}
