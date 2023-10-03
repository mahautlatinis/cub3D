/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_definition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:34:19 by malatini          #+#    #+#             */
/*   Updated: 2023/10/03 21:47:44 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	get_next_line(int fd, char **line)
{
	static char	*s;
	int			b_read;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ERROR);
	b_read = BUFFER_SIZE;
	while (b_read != 0 && !(ft_hasnewline(s)))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (!b_read == -1)
		{
			free(buffer);
			return (ERROR);
		}
		buffer[b_read] = '\0';
		s = gnl_strjoin(s, buffer);
	}
	free(buffer);
	*line = ft_newline(s);
	s = ft_prep_s(s);
	return (DONE);
}
