/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 00:50:27 by slogos            #+#    #+#             */
/*   Updated: 2016/10/26 00:50:28 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_ft.h"

static char		check_value_in_map(int i, t_result *res, t_tris piece)
{
	int x;

	x = coordinate_transformation(i, res, piece);
	if (x >= (res->edge_map * res->edge_map))
		return ('#');
	if ((x % res->edge_map) >
		(coordinate_transformation(piece.first_position, res, piece)
		% res->edge_map))
	{
		if ((i % 4 < piece.first_position % 4))
			return ('#');
	}
	else if (i % 4 > piece.first_position % 4)
		return ('#');
	return (res->map[coordinate_transformation(i, res, piece)]);
}

static int		have_place_for_tetri(t_result *res, t_tris piece)
{
	int i;

	i = piece.first_position;
	while (i < 16)
	{
		if (piece.tetriminos[i] != '.')
		{
			if (check_value_in_map(i, res, piece) != '.')
				return (0);
		}
		i++;
	}
	return (1);
}

static int		add_tetri_in_map(t_result *res, t_tris *piece)
{
	piece->pos_in_map++;
	if (piece->pos_in_map < (res->edge_map * res->edge_map))
	{
		if (have_place_for_tetri(res, *piece) > 0)
		{
			put_tetriminos(res, *piece);
			return (1);
		}
		else
			return (add_tetri_in_map(res, piece));
	}
	else
	{
		piece->pos_in_map = -1;
		return (0);
	}
}

void			tetris_resolution(t_result *res, t_tris *piece, int index)
{
	if (piece[index].tetriminos == NULL)
	{
		print_map(res);
		exit(0);
	}
	else
	{
		while (add_tetri_in_map(res, &piece[index]))
		{
			tetris_resolution(res, piece, index + 1);
			delete_tetriminos(res, piece[index]);
		}
		piece[index].pos_in_map = -1;
		if (index == 0)
		{
			res->edge_map++;
			tetris_resolution(res, piece, index);
		}
	}
}

int				coordinate_transformation(int i, t_result *res, t_tris piece)
{
	return (((i % 4) - (piece.first_position % 4))
		+ (((i / 4) - (piece.first_position / 4)) * res->edge_map)
		+ piece.pos_in_map);
}
