/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:25:22 by mahautlat         #+#    #+#             */
/*   Updated: 2023/10/03 21:56:15 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	valid_char_mini_map(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == '\n')
		return (1);
	return (0);
}

int	mini_map_all_chars(int fd, char *buffer)
{
	int	ret;
	int	is_valid;

	ret = 1;
	is_valid = 1;
	while (ret != 0)
	{
		ret = read(fd, buffer, 1);
		is_valid = valid_char_mini_map(buffer[0]);
		if (ret == -1 || is_valid == 0)
			return (ERROR);
		else if (ret == 0)
			return (SUCCESS);
	}
	return (DONE);
}

int	check_map(char *map, char *argv)
{
	int		fd;
	char	*buffer;
	int		read_ret;

	(void)map;
	buffer = (char *)malloc(sizeof(char) * 1);
	fd = open(argv, O_RDONLY);
	read_ret = 1;
	free(buffer);
	close(fd);
	return (SUCCESS);
}

int	check_cub_extension(char *str)
{
	int		i;
	char	*ext;
	int		j;

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
