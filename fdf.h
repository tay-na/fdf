/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:37:38 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/24 19:35:40 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 2600
# define HEIGHT 1800
# define MENU_W 500
# define MENU_H 1800
# define ISO 0.523599
# define HEX "abcdefxABCDEFX"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			col;
}				t_point;

typedef struct	s_coords
{
	t_point		p0;
	t_point		p1;
	t_point		d;
	t_point		s;
	t_point		start;
}				t_coords;

typedef struct	s_struct
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_pix;
	int			**map;
	int			**color;
	int			w;
	int			h;
	float		high;
	int			step;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	int			z_min;
	int			z_max;
	int			col;
	int			proj;
	int			col_count;
	t_coords	c;
}				t_struct;

/*
** color.c
*/

int				get_color(int x, int y, t_struct *fdf);
void			color_gradient(int *color, int i, int j, t_struct *fdf);
void			party_parrot(int *color, int i, int j, t_struct *fdf);
void			change_color(t_struct *fdf);
void			assign_color(t_struct *fdf);

/*
** color_utils.c
*/

double			percent(int start, int end, int current);
int				color_check(int color);
int				get_light(int start, int end, double percentage);

/*
** draw.c
*/

void			put_pixel(t_struct *fdf, int x, int y);
void			draw_line_bes(t_struct *fdf);
void			draw_l(t_point p0, t_point p1, t_struct *fdf);
int				draw_map(t_struct *fdf);
int				draw_window(t_struct *fdf);

/*
** fdf_utils.c
*/

t_struct		*initialize(void);
void			erase_image(t_struct *fdf);
void			menu_window(t_struct *fdf);
int				key_press(int key, t_struct *fdf);

/*
** keys.c
*/

void			move_map(int key, t_struct *fdf);
void			zoom_map(int key, t_struct *fdf);
void			change_projection(int key, t_struct *fdf);
void			rotate(int key, t_struct *fdf);
void			restore(int key, t_struct *fdf);

/*
** map.c
*/

void			check_validity(char *map_ch);
void			char_to_int(char *map_ch, int **map, int **color,
							t_struct *fdf);
int				get_int_arr(t_struct *fdf, char **map_ch);
void			check_argv_and_get_height(char *argv, t_struct *fdf);
int				read_map(char *argv, t_struct *fdf);

/*
** map_utils.c
*/

void			height_extremum(t_struct *fdf);
void			get_colors(char *map_ch, int **color);
void			get_heights(char *map_ch, int **map);
int				get_width(char *map_ch);

/*
** transform.c
*/

void			iso(int *x, int *y, int z);
void			rotate_x(int *y, int *z, t_struct *fdf);
void			rotate_y(int *x, int *z, t_struct *fdf);
void			rotate_z(int *x, int *y, t_struct *fdf);
t_point			change(t_point *point, t_struct *fdf);

/*
** utilities.c
*/

t_point			new_c(t_point *point, int x, int y, t_struct *fdf);
int				is_hex(char map_ch);
void			error(char *s);
void			ft_free_ch(char **s);

#endif
