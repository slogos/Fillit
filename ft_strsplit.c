/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 00:57:07 by slogos            #+#    #+#             */
/*   Updated: 2016/11/05 14:11:23 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_ft.h"

static char	*ft_strsub(char const *s, unsigned int start, int len)
{
	char	*str;
	int		i;

	if (s)
	{
		i = 0;
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (start--)
			s++;
		while (i < len && s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nb_word;
	int		i;

	if (s)
	{
		i = 0;
		nb_word = ft_array((const char *)s, c);
		if (!(t = (char **)malloc(sizeof(*t) * (nb_word + 1))))
			return (NULL);
		while (nb_word--)
		{
			if (!(t[i] = ft_strsub((const char *)s, 0, 21)))
				return (NULL);
			s = s + 21;
			i++;
		}
		t[i] = NULL;
		return (t);
	}
	return (0);
}
