/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_graphics.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:06:39 by qdam              #+#    #+#             */
/*   Updated: 2021/10/04 18:49:12 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GRAPHICS_H
# define CUB3D_GRAPHICS_H

# include "cub3D_structs.h"

// Create a TRGB color based on the value [0-255] of each color channel
t_color	create_tgrb(t_color t, t_color r, t_color g, t_color b);

// Put a pixel with a color at position (x, y) on the image
void	put_px(int x, int y, t_color color, t_img *img);

// Get the color located at the (x, y) pixel in img
t_color	get_px(int x, int y, t_img *img);

// Initialize graphics element in the game structure
char	*init_graphics(t_cub_data *cub, t_game *game);

// Free all minilibX memories allocated in the game structure
void	destroy_graphics(t_game *game);

// Make an mlx image from an XPM file and fill necessary data into img struct
void	make_image_from_xpm(void *mlx_ptr, t_img *img, char *xpm);

// Make a blank mlx image with size of (w, h) and put into img struct
void	make_image_blank(void *mlx_ptr, t_img *img, int w, int h);

// Draw the screen after the ray-casting algo
void	draw_screen(t_game *game, t_ray *rays);

/*	==== EVENT HANDLERS ==== */

int		on_destroy_win(t_game *game);
int		on_key(int key, t_game *game);
int		on_loop(t_game *game);

#endif
