/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:17:42 by qdam              #+#    #+#             */
/*   Updated: 2021/10/09 01:02:39 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

# define WIN_X		900
# define WIN_Y		700
# define WIN_TITLE	"Awesome cub3D"

# define M_PI_PI	6.28318530717958647692
# define M_SQRT2_2	0.70710678118654752440

# define FOV		1.04719755119659774615
# define SPEED_ROT	0.03141592653589793238
# define SPEED_MOV	0.05
# define N_RAYS		300

# ifdef __linux__
#  define KEY_ESC	65307
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
#  define KEY_W		'w'
#  define KEY_A		'a'
#  define KEY_S		's'
#  define KEY_D		'd'
# else
#  define KEY_ESC	53
#  define KEY_LEFT	123
#  define KEY_RIGHT	124
#  define KEY_W		13
#  define KEY_A		0
#  define KEY_S		1
#  define KEY_D		2
# endif

# define SAND 0xF7E9DB
# define RED 0xBB4211
# define RUSSIANRED 0xde300b
# define BROWN 0x54310F
# define CHOCO 0x351C04
# define MINISIDE 10
# define MINIPAD 16

#endif