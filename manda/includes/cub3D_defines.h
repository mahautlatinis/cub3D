/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:17:42 by qdam              #+#    #+#             */
/*   Updated: 2021/09/08 16:16:43 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

# define WIN_X		1200
# define WIN_Y		900
# define WIN_TITLE	"Awesome cub3D"

# define M_PI_PI	6.28318530717958647692
# define M_SQRT2_2	0.70710678118654752440

# define FOV		1.04719755119659774615
# define SPEED_ROT	0.06283185307179586477
# define SPEED_MOV	0.1
# define N_RAYS		400

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

#endif