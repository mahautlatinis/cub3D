/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_definition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:34:19 by malatini          #+#    #+#             */
/*   Updated: 2021/04/12 09:34:22 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Checker la minimap apres la definition
#include "../cub.h"

/* voir si on peut rassembler tous les shorts en une fonction ?
int check_short_definitions(int fd, char *buffer)
{
	(void)fd;
	(void)buffer;
	return (DONE);
}
*/

int	find_definitions_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R')
			//Fonction pour la resolution
		/*
		if (buffer[0] == 'W')
			//fonction pour l ouest
		if (buffer[0] == 'N')
			//fonction pour le nord
		if (buffer[0] == 'S')
			//Fonction pour le sud et les sprites (a spliter) - comment sans les sprites
		if (buffer[0] == 'E')
			//fonction pour l est
		if (buffer[0] == 'F')
			//fonction pour le field
		*/
	}
	return (SUCCESS);
}

int		get_next_line(int fd, char **line)
{
	static char *s;
	int			b_read;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX || !line)
		return (ERROR);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	b_read = BUFFER_SIZE;
	while (b_read != 0 && !(ft_hasnewline(s)))
	{
		if ((b_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (ERROR);
		}
		buffer[b_read] = '\0';
		s = gnl_strjoin(s, buffer);
	}
	free(buffer);
	*line = ft_newline(s);
	//Appeler la fonction qui check pour les definitions ici
	find_definitions_chars(line);
	s = ft_prep_s(s);
	if (b_read == 0)
		return (DONE);
	return (SUCCESS);
}
