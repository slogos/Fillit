/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:31:25 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/05 11:31:26 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_ft.h"

static void		replace_letter(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = c;
		else
			i++;
	}
}

static char		*transforme_tray(char *str)
{
	char		*s;
	int			i;
	int			j;

	i = 0;
	j = 0;
	s = (char*)malloc(sizeof(char) * 16 + 1);
	while (i < 16)
	{
		if (str[j] != '\n')
		{
			s[i] = str[j];
			i++;
			j++;
		}
		else
			j++;
	}
	s[i] = '\0';
	return (s);
}

char			**modified_array(char *str)
{
	int			i;
	char		letter;
	char		**t;

	i = 0;
	letter = 65;
	t = ft_strsplit(str, '\n');
	while (i < g_boxes)
		replace_letter(t[i++], letter++);
	return (t);
}

void			copy_tray(char **str, t_tris *tab)
{
	int index;

	index = 0;
	while (index < g_boxes)
	{
		tab[index].tetriminos = transforme_tray(str[index]);
		free(str[index]);
		tab[index].pos_in_map = -1;
		index++;
	}
	free(str);
}
