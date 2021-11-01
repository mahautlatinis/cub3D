/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:52:17 by malatini          #+#    #+#             */
/*   Updated: 2021/04/08 18:58:03 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

int     main(int argc, char **argv)
{
    if (argc <= 3)
    {
        if (argc == 2)
        {
            //Cas d erreur mauvais fichier
            //printf("%i\n", check_cub_extension(argv[1]));
            //Verification de la map
            //check_map("map/map1.cub", argv[1]);
            check_map_definition(argv[1]);
        }
    }
    return (0);
}
