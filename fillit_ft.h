/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_ft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:31:44 by slogos            #+#    #+#             */
/*   Updated: 2016/11/03 17:46:57 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FT_H
# define FILLIT_FT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUF_SIZE 1024

int				g_boxes;

typedef struct	s_result
{
	char		map[250];
	int			edge_map;
}				t_result;

typedef struct	s_tris
{
	char		*tetriminos;
	int			first_position;
	int			pos_in_map;
}				t_tris;

int				tetri_verify(char *str);
char			**ft_strsplit(char const *s, char c);
int				ft_array(const char *s, char c);
int				check_g(char *str);
int				check_l(char *str);
int				check_z_s(char *str);
int				check_t(char *str);
int				check_line_cube(char *str);
void			ft_bzero(void *s, int n);
void			init_with_points(t_result *res);
char			**modified_array(char *str);
void			copy_tray(char **str, t_tris *tab);
int				get_size(int len);
void			first_position(t_tris *tab);
void			tetris_resolution(t_result *res, t_tris *piece, int index);
void			delete_tetriminos(t_result *res, t_tris piece);
int				coordinate_transformation(int i, t_result *res, t_tris piece);
void			put_tetriminos(t_result *res, t_tris piece);
void			print_map(t_result *res);

#endif
