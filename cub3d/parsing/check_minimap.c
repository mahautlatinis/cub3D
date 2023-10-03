/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:25:22 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/08 19:28:25 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

//Il faut traiter differemment deux parties du fichiers .cub
int		valid_char_mini_map(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == '\n')
		//Attention a cette condition, pour l instant c est ok
		//faire une isspace ? ou eviter ?
		//Doit marcher pour la minimap mais pas pour le reste
		//|| c == '\t')
		return (1);
	return (0);
}

//On check char par char
//nom de la fonction pas tres bien choisi
//"Mise a part la description de la map, chaque element peut etre separe par un ou plusieurs espaces"
int		mini_map_all_chars(int fd, char *buffer)
{
	int ret;
	int is_valid;
	//int i;

	ret = 1;
	is_valid = 1;
	//i = 0;
	while (ret != 0)
	{
		//printf("buffer[0] = %c\n", buffer[0]);
		ret = read(fd, buffer, 1);
		is_valid = valid_char_mini_map(buffer[0]);
		if (ret == -1 || is_valid == 0)
		{
			//free(buffer);
			printf("Incorrect map !\n");
			return (ERROR);
		}
		else if (ret == 0)
			return (SUCCESS);
	}
	//printf("Valid character in map\n");
	//printf("Success !\n");
	return (DONE);
}

int		check_map(char *map, char *argv)
{
	int		fd;
	char	*buffer;
	int		read_ret;

	//printf("coucou\n");
	//printf("Test : %s\n", argv);
	(void)map;//A changer
	buffer = (char *)malloc(sizeof(char) * 1);
	//A modifier pour s adapter a differentes map
	fd = open(argv, O_RDONLY);
	//printf("Mon fd : %i\n", fd);
	read_ret = 1;
	//Appeler apres quand on a fini les verifs pour la definition
	if ((mini_map_all_chars(fd, buffer)) == 1)
			printf("Your mini map is valid !\n");
	else if ((mini_map_all_chars(fd, buffer)) <= 0)
		printf("Your map is not valid !\n");
	free(buffer);
	close(fd);
	return (SUCCESS);//Attention a la gestion des erreurs
}

int     check_cub_extension(char *str)
{
    int     i;
    char    *ext;
    int      j;

    ext = ft_strdup(".cub");
    i = 0;
    j = 0;
    while (str[i] != '.' && str[i])
        i++;
    if (str[i])
    {
        while (str[i] == ext[j] && ext[j] && str[i])
        {
            i++;
            j++;
        }
        if (j == 4 && str[i] == '\0')
        {
            free (ext);
            return (1);
        }
    }
    free(ext);
    return (0);
}
