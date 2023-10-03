/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_raycasting.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:06:42 by qdam              #+#    #+#             */
/*   Updated: 2021/09/08 16:06:42 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCASTING_H
# define CUB3D_RAYCASTING_H

# include "cub3D_structs.h"

// Run the ray casting algorithm and put data into game struct
void	ray_casting(t_game *game, t_ray *rays);

// Calculate one ray's properties
void	calculate_ray(t_game *game, t_ray *ray);

// Get the equation for a line which goes through pt on a 2-d plane forming
// an angle to the y-axis. Put the equation's parameters into the line
// pointer. Line's equation is of form (ax + by + c = 0)
void	get_line_equation(t_vector *pt, double angle, t_line *line);

// Return the interception point of either a horizontal (y = val) or vertical
// line (x = val) with a line of form (ax + by + c = 0). y_line signifies if
// the former line is horizontal (true) or vertical (false). If horizontal
// line is specified, interception's x is returned, otherwise its y. A special
// case which always returns infinity is when the two lines are parallel or is
// the same line (0 or infinite number of interceptions)
double	get_intercept(t_line *line, double val, bool y_line);

// Return the euclidean distance between two points on the 2-d plane
double	distance_points(t_vector *p1, t_vector *p2);

#endif