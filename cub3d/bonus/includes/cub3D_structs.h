/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:20:10 by qdam              #+#    #+#             */
/*   Updated: 2021/10/09 02:02:37 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef struct s_list	t_list;
typedef unsigned int	t_color;

typedef enum e_direction
{
	NO,
	SO,
	WE,
	EA,
	NONE
}	t_dir;

typedef struct s_cub_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	t_list	*raw_map;
}	t_cub_data;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_line_equation
{
	double	a;
	double	b;
	double	c;
}	t_line;

typedef struct s_mlx_img
{
	int		w;
	int		h;
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		end;
}	t_img;

typedef struct s_player
{
	t_vector	pos;
	double		dir;
	bool		move_no;
	bool		move_so;
	bool		move_we;
	bool		move_ea;
	bool		rotate_l;
	bool		rotate_r;
	bool		mouse_rotating;
}	t_player;

typedef struct s_shape
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_shape;

typedef struct s_game
{
	char		**map;
	int			map_w;
	int			map_h;
	t_player	p;
	void		*ptr;
	void		*win;
	t_img		scr;
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_color		flo;
	t_color		cei;
	bool		minimap_drawable;
}	t_game;

typedef struct s_ray
{
	double		angle_rel;
	double		angle_abs;
	double		wall_dist;
	t_dir		wall_dir;
	t_vector	end;
	int			wall_height;
	int			draw_height;
}	t_ray;

#endif
