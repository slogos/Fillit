/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:23:50 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/05 11:23:51 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_ft.h"

static int		size_verify(char *str)
{
	int i;
	int tetri_n;
	int dot_n;

	i = 0;
	tetri_n = 0;
	dot_n = 0;
	while (str[i])
	{
		if (str[i] == '#')
			tetri_n++;
		else if (str[i] == '.')
			dot_n++;
		i++;
	}
	if (((++i % 21) == 0) && ((tetri_n % 4) == 0) && ((dot_n % 12) == 0))
		return (1);
	else
		return (0);
}

static int		dot_hash_chk(char *str)
{
	int i;
	int tetri_n;
	int dot_n;

	i = 0;
	tetri_n = 0;
	dot_n = 0;
	while (str[i])
	{
		if (str[i] == '#')
			tetri_n++;
		else if (str[i] == '.')
			dot_n++;
		i++;
	}
	if (((tetri_n % 4) == 0) && ((dot_n % 12) == 0))
		return (1);
	else
		return (0);
}

static int		validate_tetri(char *str)
{
	if (((check_g(str) + check_l(str) + check_z_s(str) + \
		check_t(str) + check_line_cube(str)) == 1) && \
		dot_hash_chk(str) == 1)
		return (1);
	return (0);
}

int				tetri_verify(char *str)
{
	int		count;
	int		i;
	char	**t;

	count = 0;
	i = 0;
	t = ft_strsplit(str, '\n');
	while (i < g_boxes)
	{
		if ((size_verify(str) == 1) && (validate_tetri(t[i]) == 1))
			count++;
		else
			break ;
		i++;
	}
	if (count == g_boxes)
		return (1);
	else
		return (0);
}
