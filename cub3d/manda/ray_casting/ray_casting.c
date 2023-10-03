/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:44:39 by qdam              #+#    #+#             */
/*   Updated: 2021/10/09 01:55:29 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static inline void	init_rays(t_ray *rays, bool *done_init_rays)
{
	int	i;

	i = -1;
	while (++i < N_RAYS)
	{
		rays[i].angle_rel = -FOV * 0.5 + (double)i * (FOV / (double)(N_RAYS));
		rays[i].angle_abs = 0.0;
		rays[i].wall_dist = 0.0;
		rays[i].wall_dir = NONE;
		rays[i].end.x = 0.0;
		rays[i].end.y = 0.0;
		rays[i].wall_height = 0;
		rays[i].draw_height = 0;
	}
	*done_init_rays = true;
}

void	ray_casting(t_game *game, t_ray *rays)
{
	static bool	done_init_rays = false;
	int			i;

	if (!done_init_rays)
		init_rays(rays, &done_init_rays);
	i = -1;
	while (++i < N_RAYS)
	{
		rays[i].angle_abs = game->p.dir + rays[i].angle_rel;
		calculate_ray(game, &rays[i]);
	}
}
