/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:37:38 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/13 18:37:21 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include <math.h>

# include <stdio.h>

# define WIDTH 2800
# define HEIGHT 1800
# define MENU_W 500
# define MENU_H 1800
# define ISO 0.523599

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		col;
}				t_point;

typedef struct	s_coords
{
	t_point p0;
	t_point p1;
	t_point d;
	t_point s;
	t_point	start;
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
	int			col;
	int			proj;
	t_coords	c;
}				t_struct;

void	char_to_int(char *map_ch, int **map, int **color, t_struct *fdf);
int		get_int_arr(t_struct *fdf, char **map_ch);
int		read_map(char *argv, t_struct *fdf);
void	put_pixel(t_struct *fdf, int x, int y);
void	draw_line_bes(t_struct *fdf);
void	draw_line(t_point p0, t_point p1, t_struct *fdf);
int		draw_map(t_struct *fdf);
int		deal_key(int key, void *param);
int		draw_window(t_struct *fdf);
int		key_press(int key, t_struct *fdf);
void	move_map(int key, t_struct *fdf);
void	erase_image(t_struct *fdf);
t_point	change(t_point *point, t_struct *fdf);
t_point	new_c(t_point *point, int x, int y, int z);
void	menu_window(t_struct *fdf);
int		ft_atoi_base(char *str, int base);
void	error(char *s);

#endif

//|| (ft_toupper(map_ch[i]) >= 'A' && ft_toupper(map_ch[i]) <= 'F')
/* 
while(map_ch[i])
	{
		if (map_ch[i] == ',')
		{
			//i++;
       		if (map_ch[i + 1] == '0' && map_ch[i + 2] == 'x')
        	{
				i += 3;
        		(*color)[f] = ft_atoi_base(&map_ch[i], 16);
        		f++;
        		while (ft_isdigit(map_ch[i]) || (ft_toupper(map_ch[i]) >= 'A' && ft_toupper(map_ch[i]) <= 'F'))
           			i++;
			}
 		}
		else if (ft_isdigit(map_ch[i]))
		{
			(*map)[c] = ft_atoi(&map_ch[i]);
			c++;
			while (ft_isdigit(map_ch[i]))
				i++;
		}
       	else
       	{
          	i++;
       		(*color)[f] = 1;
       		f++;
       	}
		//i++;
	} */