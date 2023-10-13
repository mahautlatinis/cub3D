/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:02:37 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:45:29 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static inline double
	get_min_dist_h(t_ray *ray, t_game *game, t_line *line, t_vector *end)
{
	double	d_iter;
	double	y;
	double	x;

	if (line->a == 0.0)
		return (INFINITY);
	d_iter = (sin(ray->angle_abs) > 0) - (sin(ray->angle_abs) < 0);
	y = (double)((int)(game->p.pos.y) + (d_iter == 1.0));
	while (0.0 <= y && y < (double)(game->map_h))
	{
		x = get_intercept(line, y, true);
		if (x < 0 || x >= (double)(game->map_w)
			|| game->map[(int)y - (d_iter == -1.0)][(int)x] != '0')
			break ;
		y += d_iter;
	}
	end->x = x;
	end->y = y;
	return (distance_points(&game->p.pos, end));
}

static inline double
	get_min_dist_v(t_ray *ray, t_game *game, t_line *line, t_vector *end)
{
	double	d_iter;
	double	x;
	double	y;

	if (line->b == 0.0)
		return (INFINITY);
	d_iter = (cos(ray->angle_abs) > 0) - (cos(ray->angle_abs) < 0);
	x = (double)((int)(game->p.pos.x) + (d_iter == 1.0));
	while (0.0 <= x && x < (double)(game->map_w))
	{
		y = get_intercept(line, x, false);
		if (y < 0 || y >= (double)(game->map_h)
			|| game->map[(int)y][(int)x - (d_iter == -1.0)] != '0')
			break ;
		x += d_iter;
	}
	end->x = x;
	end->y = y;
	return (distance_points(&game->p.pos, end));
}

void	calculate_ray(t_game *game, t_ray *ray)
{
	t_line		line;
	t_vector	min_dist;
	t_vector	end_v;
	t_vector	end_h;
	bool		no_or_we;

	get_line_equation(&game->p.pos, ray->angle_abs, &line);
	min_dist.x = get_min_dist_v(ray, game, &line, &end_v);
	min_dist.y = get_min_dist_h(ray, game, &line, &end_h);
	if (min_dist.x >= min_dist.y)
	{
		no_or_we = game->p.pos.y < end_h.y;
		ray->wall_dist = min_dist.y;
		ray->wall_dir = (no_or_we) * NO + (!no_or_we) * SO;
		ft_memcpy(&ray->end, &end_h, sizeof(t_vector));
	}
	else
	{
		no_or_we = game->p.pos.x < end_v.x;
		ray->wall_dist = min_dist.x;
		ray->wall_dir = (no_or_we) * WE + (!no_or_we) * EA;
		ft_memcpy(&ray->end, &end_v, sizeof(t_vector));
	}
	return ;
}
