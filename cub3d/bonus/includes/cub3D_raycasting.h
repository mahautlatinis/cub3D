/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_raycasting.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:06:42 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:33:53 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCASTING_H
# define CUB3D_RAYCASTING_H

# include "cub3D_structs.h"

double	distance_points(t_vector *p1, t_vector *p2);
double	get_intercept(t_line *line, double val, bool y_line);
void	calculate_ray(t_game *game, t_ray *ray);
void	get_line_equation(t_vector *pt, double angle, t_line *line);
void	ray_casting(t_game *game, t_ray *rays);

#endif