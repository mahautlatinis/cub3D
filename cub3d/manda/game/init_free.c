/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:03:48 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:40:19 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static inline void	set_player_initial_pos(t_game *game)
{
	int		x;
	int		y;
	bool	done;

	y = -1;
	done = false;
	while (!done && game->map[++y])
	{
		x = -1;
		while (!done && game->map[y][++x])
			if (ft_strchr("NSWE", game->map[y][x]))
				done = true;
	}
	game->p.pos.x = (double)x + 0.5;
	game->p.pos.y = (double)y + 0.5;
	if (game->map[y][x] == 'E')
		game->p.dir = 0.0;
	else if (game->map[y][x] == 'N')
		game->p.dir = 1.5 * M_PI;
	else if (game->map[y][x] == 'W')
		game->p.dir = M_PI;
	else
		game->p.dir = 0.5 * M_PI;
	game->map[y][x] = '0';
	return ;
}

char	*init_game(t_cub_data *cub, t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->map = make_char_map(cub->raw_map);
	if (!game->map)
		return (MALLOC_CHARMAP);
	game->map_w = max_list_str_len(cub->raw_map);
	game->map_h = ft_lstsize(cub->raw_map);
	set_player_initial_pos(game);
	return (init_graphics(cub, game));
}

void	destroy_game(t_game *game, bool quit)
{
	if (game->map)
		free_tab(game->map);
	destroy_graphics(game);
	if (quit)
		exit(0);
	return ;
}
