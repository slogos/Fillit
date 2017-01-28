/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:18:22 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/05 14:02:22 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_ft.h"

int		check_g(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 5] == '#' && \
			str[i + 10] == '#' && str[i + 11] == '#')
			count++;
		else if (str[i] == '#' && str[i + 3] == '#' && \
			str[i + 4] == '#' && str[i + 5] == '#')
			count++;
		else if (str[i] == '#' && str[i + 1] == '#' && \
			str[i + 6] == '#' && str[i + 11] == '#')
			count++;
		else if (str[i] == '#' && str[i + 1] == '#' && \
			str[i + 2] == '#' && str[i + 5] == '#')
			count++;
		i++;
	}
	return (count);
}

int		check_l(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 5] == '#' && \
			str[i + 9] == '#' && str[i + 10] == '#')
			count++;
		else if (str[i] == '#' && str[i + 1] == '#' && \
			str[i + 2] == '#' && str[i + 7] == '#')
			count++;
		else if (str[i] == '#' && str[i + 1] == '#' && \
			str[i + 5] == '#' && str[i + 10] == '#')
			count++;
		else if (str[i] == '#' && str[i + 5] == '#' && \
			str[i + 6] == '#' && str[i + 7] == '#')
			count++;
		i++;
	}
	return (count);
}

int		check_z_s(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 1] == '#' && \
			str[i + 6] == '#' && str[i + 7] == '#')
			count++;
		else if (str[i] == '#' && str[i + 4] == '#' && \
			str[i + 5] == '#' && str[i + 9] == '#')
			count++;
		else if (str[i] == '#' && str[i + 1] == '#' && \
			str[i + 4] == '#' && str[i + 5] == '#')
			count++;
		else if (str[i] == '#' && str[i + 5] == '#' && \
			str[i + 6] == '#' && str[i + 11] == '#')
			count++;
		i++;
	}
	return (count);
}

int		check_t(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 1] == '#' && \
			str[i + 2] == '#' && str[i + 6] == '#')
			count++;
		else if (str[i] == '#' && str[i + 5] == '#' && \
			str[i + 6] == '#' && str[i + 10] == '#')
			count++;
		else if (str[i] == '#' && str[i + 4] == '#' && \
			str[i + 5] == '#' && str[i + 6] == '#')
			count++;
		else if (str[i] == '#' && str[i + 4] == '#' && \
			str[i + 5] == '#' && str[i + 10] == '#')
			count++;
		i++;
	}
	return (count);
}

int		check_line_cube(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 5] == '#' && \
			str[i + 10] == '#' && str[i + 15] == '#')
			count++;
		else if (str[i] == '#' && str[i + 1] == '#' && \
			str[i + 5] == '#' && str[i + 6] == '#')
			count++;
		else if (str[i] == '#' && str[i + 1] == '#' && \
			str[i + 2] == '#' && str[i + 3] == '#')
			count++;
		i++;
	}
	return (count);
}
