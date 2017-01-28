/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 00:50:27 by slogos            #+#    #+#             */
/*   Updated: 2016/10/26 00:50:28 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_ft.h"

int			ft_array(const char *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] == c)
			count++;
		i++;
	}
	g_boxes = ++count;
	return (count);
}

void		ft_bzero(void *s, int n)
{
	char *t;

	t = s;
	while (n != 0)
	{
		*t++ = 0;
		n--;
	}
}

void		init_with_points(t_result *res)
{
	int i;

	i = 0;
	while (i < 250)
	{
		res->map[i] = '.';
		i++;
	}
}

int			get_size(int len)
{
	int i;

	i = 2;
	while ((i * i) < ((++len / 21) * 4))
		i++;
	return (i);
}

void		first_position(t_tris *tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i].tetriminos != NULL)
	{
		j = 0;
		while (tab[i].tetriminos[j] == '.')
			j++;
		tab[i].first_position = j;
		i++;
	}
}
