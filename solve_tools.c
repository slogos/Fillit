/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 00:50:27 by slogos            #+#    #+#             */
/*   Updated: 2016/10/26 00:50:28 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_ft.h"

void	print_map(t_result *res)
{
	int i;

	i = 0;
	while (i < res->edge_map)
	{
		write(1, res->map + (i * res->edge_map), res->edge_map);
		write(1, "\n", 1);
		i++;
	}
}

void	delete_tetriminos(t_result *res, t_tris piece)
{
	int i;

	i = 0;
	while (i < (res->edge_map * res->edge_map))
	{
		if (res->map[i] == piece.tetriminos[piece.first_position])
			res->map[i] = '.';
		i++;
	}
}

void	put_tetriminos(t_result *res, t_tris piece)
{
	int i;

	i = piece.first_position;
	while (i < 16)
	{
		if (piece.tetriminos[i] != '.')
			res->map[coordinate_transformation(i, res, piece)] =
			piece.tetriminos[i];
		i++;
	}
}
