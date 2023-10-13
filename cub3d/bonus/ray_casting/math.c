/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:33:52 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:33:55 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	get_line_equation(t_vector *pt, double angle, t_line *line)
{
	if (cos(angle) == 0.0)
	{
		line->a = 1.0;
		line->b = 0.0;
		line->c = -pt->x;
	}
	else
	{
		line->a = tan(angle);
		line->b = -1.0;
		line->c = pt->y - line->a * pt->x;
	}
	return ;
}

double	get_intercept(t_line *line, double val, bool y_line)
{
	if ((y_line && line->a == 0.0) || (!y_line && line->b == 0.0))
		return (INFINITY);
	if (y_line)
		return ((line->c + line->b * val) / (-line->a));
	return ((line->c + line->a * val) / (-line->b));
}

double	distance_points(t_vector *p1, t_vector *p2)
{
	return (sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2)));
}
