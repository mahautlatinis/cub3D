/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:13:20 by malatini          #+#    #+#             */
/*   Updated: 2021/04/08 18:59:43 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

//Probleme de sauvegarde des fichiers de la minilibx-linux (voir comment regler ca ?)
//#include "./minilibx-linux/mlx.h"
# include <fcntl.h>

# define ERROR -1
# define DONE 0
# define SUCCESS 1

//Faire une fonction qui initialise la structure
typedef struct s_map
{
	short	r[2];
	char	*we;
	char	*no;
	char	*so;
	char	*ea;
	char	*s;
	short	f[3];
	short	c[3];
	//Noter les y et les x ?
}				t_map;

//check_map.c
//Verifier que le fichier fini par .cub
int     check_cub_extension(char *str);
//Fonction generale de check de la map (a revoir)
int     check_map(char *map, char *argv);
//Check d un char
int     valid_char_mini_map(char c);
//Check de tous les char
int		mini_map_all_chars(int fd, char *buffer);

//check_map_definitions
int	check_map_definition(char *argv);//int fd, , char *buffer

//utils
char	*ft_strdup(const char *s1);

//colors
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

#endif

