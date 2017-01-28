/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 00:27:55 by slogos            #+#    #+#             */
/*   Updated: 2016/11/03 17:51:03 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_ft.h"

static void		console(char *buf, int ret)
{
	t_result	res;
	t_tris		tab[27];

	ft_bzero(tab, 27 * sizeof(*tab));
	init_with_points(&res);
	copy_tray(modified_array(buf), tab);
	res.edge_map = get_size(ret);
	first_position(tab);
	tetris_resolution(&res, tab, 0);
}

int				main(int ac, char **av)
{
	int			fd;
	int			ret;
	char		buf[BUF_SIZE];

	if (ac != 2)
	{
		write(1, "usage: ./fillit file_name\n", 26);
		exit(1);
	}
	if (((fd = open(av[1], O_RDONLY)) == -1) ||
		((ret = read(fd, buf, BUF_SIZE)) == 0))
	{
		write(1, "error\n", 6);
		exit(1);
	}
	buf[ret] = '\0';
	close(fd);
	if (ret <= 545 && tetri_verify(buf) == 1)
		console(buf, ret);
	else
		write(1, "error\n", 6);
	return (0);
}
