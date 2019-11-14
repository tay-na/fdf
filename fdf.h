/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:37:38 by tollivan          #+#    #+#             */
/*   Updated: 2019/11/14 19:14:01 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include <math.h>

# include <stdio.h>

typedef struct	s_point
{
	int		x;
	int		y;	
}				t_point;

typedef struct	s_coords
{
	t_point p0;
	t_point p1;
	t_point d;
	t_point s;
}				t_coords;

typedef struct	s_struct
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_pix;
	int			**map;
	int			w;
	int			h;
	int			step;
	int			col;
	t_coords	coords;
}				t_struct;

void	char_to_int(char *map_ch, int *map, t_struct *fdf);
int		get_int_arr(t_struct *fdf, char **map_ch);
int		read_map(char *argv, t_struct *fdf);
void	put_pixel(t_struct *fdf, int x, int y);
void	draw_line_bes(t_struct *fdf);
void	draw_line(t_struct *fdf);
int		draw_map(t_struct *fdf);
int		deal_key(int key, void *param);
int		draw_window(t_struct *fdf);

#endif