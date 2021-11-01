/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:13:05 by qdam              #+#    #+#             */
/*   Updated: 2021/10/09 01:55:29 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	on_loop(t_game *game)
{
	static t_player	p = {{-1.0, -1.0}, -1.0};
	static t_ray	rays[N_RAYS];

	if (p.pos.x == game->p.pos.x && p.pos.y == game->p.pos.y
		&& p.dir == game->p.dir)
		return (0);
	mlx_clear_window(game->ptr, game->win);
	p.pos.x = game->p.pos.x;
	p.pos.y = game->p.pos.y;
	p.dir = game->p.dir;
	ray_casting(game, rays);
	draw_screen(game, rays);
	mlx_put_image_to_window(game->ptr, game->win, game->scr.img, 0, 0);
	return (0);
}

int	on_destroy_win(t_game *game)
{
	destroy_game(game, true);
	return (0);
}

int	on_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		destroy_game(game, true);
	if (key == KEY_LEFT)
		player_rotate(game, -SPEED_ROT);
	if (key == KEY_RIGHT)
		player_rotate(game, SPEED_ROT);
	if (key == KEY_W)
		player_move(game, SPEED_MOV, 0);
	if (key == KEY_S)
		player_move(game, SPEED_MOV, M_PI);
	if (key == KEY_A)
		player_move(game, SPEED_MOV, -M_PI_2);
	if (key == KEY_D)
		player_move(game, SPEED_MOV, M_PI_2);
	return (0);
}
