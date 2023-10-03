/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse_mac.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:11:33 by qdam              #+#    #+#             */
/*   Updated: 2021/10/09 02:03:17 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	on_mouse_move(int x, int y, t_game *game)
{
	double const	default_mouse_x = WIN_X / 2;
	double const	default_mouse_y = WIN_Y / 2;
	double			dx;

	(void)y;
	if (x == default_mouse_x)
		return (0);
	dx = 4 * FOV * (x - default_mouse_x) / WIN_X;
	player_rotate(game, dx);
	game->p.mouse_rotating = true;
	mlx_mouse_move(game->win, default_mouse_x, default_mouse_y);
	return (0);
}
