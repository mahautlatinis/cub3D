/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:54:23 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:41:29 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static inline char	*load_wall_textures(t_cub_data *cub, t_game *game)
{
	make_image_from_xpm(game->ptr, &game->no, cub->no);
	make_image_from_xpm(game->ptr, &game->so, cub->so);
	make_image_from_xpm(game->ptr, &game->we, cub->we);
	make_image_from_xpm(game->ptr, &game->ea, cub->ea);
	if (game->no.img == NULL || game->so.img == NULL
		|| game->we.img == NULL || game->ea.img == NULL)
		return (TEXTURE_CORRUPT);
	return (NULL);
}

char	*init_graphics(t_cub_data *cub, t_game *game)
{
	game->ptr = mlx_init();
	if (!game->ptr)
		return (GRAPHICS_INIT);
	game->win = mlx_new_window(game->ptr, WIN_X, WIN_Y, WIN_TITLE);
	if (!game->win)
		return (WINDOW_INIT);
	make_image_blank(game->ptr, &game->scr, WIN_X, WIN_Y);
	if (!(game->scr.img))
		return (WINDOW_IMG_INIT);
	game->flo = create_tgrb(0, cub->f_r, cub->f_g, cub->f_b);
	game->cei = create_tgrb(0, cub->c_r, cub->c_g, cub->c_b);
	mlx_hook(game->win, 2, 1L << 0, on_key, game);
	mlx_hook(game->win, 17, 0L, on_destroy_win, game);
	mlx_loop_hook(game->ptr, on_loop, game);
	return (load_wall_textures(cub, game));
}

void	destroy_graphics(t_game *game)
{
	if (!game->ptr)
		return ;
	if (game->scr.img)
		mlx_destroy_image(game->ptr, game->scr.img);
	if (game->no.img)
		mlx_destroy_image(game->ptr, game->no.img);
	if (game->so.img)
		mlx_destroy_image(game->ptr, game->so.img);
	if (game->we.img)
		mlx_destroy_image(game->ptr, game->we.img);
	if (game->ea.img)
		mlx_destroy_image(game->ptr, game->ea.img);
	if (game->win)
		mlx_destroy_window(game->ptr, game->win);
	if (USING_LINUX)
	{
		mlx_destroy_display(game->ptr);
		free(game->ptr);
	}
	return ;
}
