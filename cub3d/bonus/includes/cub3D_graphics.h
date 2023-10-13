/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_graphics.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:06:39 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:33:53 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GRAPHICS_H
# define CUB3D_GRAPHICS_H

# include "cub3D_structs.h"

char	*init_graphics(t_cub_data *cub, t_game *game);
t_color	create_tgrb(t_color t, t_color r, t_color g, t_color b);
t_color	get_px(int x, int y, t_img *img);
void	destroy_graphics(t_game *game);
void	draw_minimap(t_game *game, t_ray *rays);
void	draw_screen(t_game *game, t_ray *rays);
void	make_image_blank(void *mlx_ptr, t_img *img, int w, int h);
void	make_image_from_xpm(void *mlx_ptr, t_img *img, char *xpm);
void	put_px(int x, int y, t_color color, t_img *img);

/*	==== EVENT HANDLERS ==== */

int		on_destroy_win(t_game *game);
int		on_key_press(int key, t_game *game);
int		on_key_release(int key, t_game *game);
int		on_loop(t_game *game);
int		on_mouse_move(int x, int y, t_game *game);

#endif
