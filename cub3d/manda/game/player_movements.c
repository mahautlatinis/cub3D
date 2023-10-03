/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:08:40 by qdam              #+#    #+#             */
/*   Updated: 2021/10/09 01:55:29 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Check if player can move (dx, dy). This is mostly a collison check
static inline bool	can_move(t_game *game, double dx, double dy)
{
	double const	lim_wall = 0.05;
	double			x;
	double			y;

	x = game->p.pos.x + dx;
	y = game->p.pos.y + dy;
	return (0 <= x && x < WIN_X && 0 <= y && y < WIN_Y
		&& game->map[(int)(y + lim_wall)][(int)(x + lim_wall)] == '0'
		&& game->map[(int)(y - lim_wall)][(int)(x - lim_wall)] == '0'
		&& game->map[(int)(y + lim_wall)][(int)(x - lim_wall)] == '0'
		&& game->map[(int)(y - lim_wall)][(int)(x + lim_wall)] == '0');
}

void	player_rotate(t_game *game, double speed)
{
	double	dir;

	dir = game->p.dir + speed;
	if (dir < 0.0)
		game->p.dir = dir + M_PI_PI;
	else if (dir >= M_PI_PI)
		game->p.dir = dir - M_PI_PI;
	else
		game->p.dir = dir;
}

void	player_move(t_game *game, double speed, double angle)
{
	double	dx;
	double	dy;

	angle += game->p.dir;
	dx = speed * cos(angle);
	dy = speed * sin(angle);
	if (can_move(game, dx, 0))
		game->p.pos.x += dx;
	if (can_move(game, 0, dy))
		game->p.pos.y += dy;
}
