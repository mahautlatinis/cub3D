/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:06:35 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:43:08 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_H
# define CUB3D_GAME_H

# include "cub3D_structs.h"

char	*init_game(t_cub_data *cub, t_game *game);
void	destroy_game(t_game *game, bool quit);
void	launch_game(t_game *game);
void	player_move(t_game *game, double speed, double angle);
void	player_rotate(t_game *game, double d_angle);

#endif
