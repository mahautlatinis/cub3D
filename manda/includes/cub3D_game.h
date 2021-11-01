/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:06:35 by qdam              #+#    #+#             */
/*   Updated: 2021/10/09 01:52:20 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_H
# define CUB3D_GAME_H

# include "cub3D_structs.h"

// Initialize the game struct. Return an error message if any, otherwise NULL
char	*init_game(t_cub_data *cub, t_game *game);

// The main game's loop
void	launch_game(t_game *game);

// Rotate player by an angle of d_angle radians
void	player_rotate(t_game *game, double d_angle);

// Move the player
void	player_move(t_game *game, double speed, double angle);

// Free all memories allocated in the game structure
void	destroy_game(t_game *game, bool quit);

#endif
