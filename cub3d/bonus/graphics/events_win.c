/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:23:49 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:18:38 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static inline bool	player_moving(t_player *p)
{
	static bool	first_run = true;

	if (first_run)
	{
		first_run = false;
		return (true);
	}
	return (p->move_no || p->move_so || p->move_we || p->move_ea
		|| p->rotate_l || p->rotate_r /*|| p->mouse_rotating*/);
}

static inline void	update_player(t_game *game)
{
	if (game->p.rotate_l)
		player_rotate(game, -SPEED_ROT);
	if (game->p.rotate_r)
		player_rotate(game, SPEED_ROT);
	if (game->p.move_no)
		player_move(game, SPEED_MOV, 0.0);
	if (game->p.move_so)
		player_move(game, SPEED_MOV, M_PI);
	if (game->p.move_we)
		player_move(game, SPEED_MOV, -M_PI_2);
	if (game->p.move_ea)
		player_move(game, SPEED_MOV, M_PI_2);
	return ;
}

int	on_loop(t_game *game)
{
	static t_ray	rays[N_RAYS];

	if (!player_moving(&game->p))
		return (0);
	update_player(game);
	mlx_clear_window(game->ptr, game->win);
	ray_casting(game, rays);
	draw_screen(game, rays);
	draw_minimap(game, rays);
	mlx_put_image_to_window(game->ptr, game->win, game->scr.img, 0, 0);
	return (0);
}

int	on_destroy_win(t_game *game)
{
	destroy_game(game, true);
	return (0);
}
