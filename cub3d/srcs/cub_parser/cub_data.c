/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:01:33 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:39:18 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_cub_data(t_cub_data *cub)
{
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->f_r = -1;
	cub->f_g = -1;
	cub->f_b = -1;
	cub->c_r = -1;
	cub->c_g = -1;
	cub->c_b = -1;
	cub->raw_map = NULL;
	return ;
}

void	free_cub_data(t_cub_data *cub)
{
	if (!cub)
		return ;
	if (cub->no)
		free(cub->no);
	if (cub->so)
		free(cub->so);
	if (cub->we)
		free(cub->we);
	if (cub->ea)
		free(cub->ea);
	ft_lstclear(&cub->raw_map, free);
	return ;
}
