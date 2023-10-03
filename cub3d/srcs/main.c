/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:37:00 by qdam              #+#    #+#             */
/*   Updated: 2023/10/03 22:16:53 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tab(char **tab)
{
	size_t	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	error_then_exit(char *fname, char *msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (fname)
	{
		ft_putstr_fd(fname, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	else
		ft_putstr_fd(UNKN_ERROR, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(0);
}

int	main(int ac, char **av)
{
	t_cub_data	cub;
	int			fd;
	char		*parse_error;

	if (ac != 2)
		error_then_exit(NULL, ARG_ERROR);
	if (!check_file_ext(av[1], ".cub"))
		error_then_exit(av[1], NAME_ERROR);
	if (!can_read_file(av[1]))
		error_then_exit(av[1], READ_ERROR);
	fd = open(av[1], O_RDONLY);
	init_cub_data(&cub);
	parse_error = parse_cub(&cub, fd);
	if (parse_error && close(fd) <= 0)
		error_then_exit(av[1], parse_error);
	close(fd);
	free_cub_data(&cub);
	puts("Everything good");
}
