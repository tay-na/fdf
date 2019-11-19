/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:10:00 by tollivan          #+#    #+#             */
/*   Updated: 2019/11/19 19:16:28 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_struct *fdf, int x, int y)
{
	int		p;

	p = y * 1000 + x;
	fdf->img_pix[p] = fdf->col; 
}

void	iso(int *x, int *y/*,  int z */)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = /* -z +  */(previous_x + previous_y) * sin(0.523599);
}

void	draw_line_bes(t_struct *fdf)
{
	int		x;
	int		y;
	int		err;
	int		err2;

	x = fdf->coords.p0.x;
	y = fdf->coords.p0.y;
	err = fdf->coords.d.x - fdf->coords.d.y;
	while (x != fdf->coords.p1.x || y != fdf->coords.p1.y)
	{
		put_pixel(fdf, x, y);
		err2 = err * 2;
		if (err2 > fdf->coords.d.y * -1)
		{
			err = err - fdf->coords.d.y;
			x = x + fdf->coords.s.x;
		}
		if (err2 < fdf->coords.d.x)
		{
			err = err + fdf->coords.d.x;
			y = y + fdf->coords.s.y;
		}
	}
	put_pixel(fdf, x, y);
}

void	draw_line(t_struct *fdf)
{
	fdf->coords.d.x = abs(fdf->coords.p1.x - fdf->coords.p0.x);
	fdf->coords.d.y = abs(fdf->coords.p1.y - fdf->coords.p0.y);
	fdf->coords.s.x = fdf->coords.p0.x < fdf->coords.p1.x ? 1 : -1;
	fdf->coords.s.y = fdf->coords.p0.y < fdf->coords.p1.y ? 1 : -1;
	draw_line_bes(fdf);
}

int		draw_hor(t_struct *fdf)
{
	int		i;
	int		j;
	
	i = 0;
	fdf->col = 0xFFC000;
	while (i < fdf->h)
	{
		j = 0;
		while (j < fdf->w - 1)
		{
			fdf->coords.p0.y = i * fdf->step + fdf->coords.start.x;
			fdf->coords.p0.x = j * fdf->step + fdf->coords.start.y;
			fdf->coords.p1.y = i * fdf->step + fdf->coords.start.x;
			fdf->coords.p1.x = (j + 1) * fdf->step + fdf->coords.start.y;
			if (fdf->proj == 150)
			{
				iso(&fdf->coords.p0.x, &fdf->coords.p0.y);
				iso(&fdf->coords.p1.x, &fdf->coords.p1.y);
			}
			draw_line(fdf);
			j++;
		}
		i++;
	}
	return (0);
}

int		draw_vert(t_struct *fdf)
{
	int		i;
	int		j;
	i = 0;
	fdf->col = 0xFFFFFF;
	
	while (i < fdf->w)
	{
		j = 0;
		while (j < fdf->h - 1)
		{
			fdf->coords.p0.x = i * fdf->step + fdf->coords.start.y;
			fdf->coords.p0.y = j * fdf->step + fdf->coords.start.x;
			fdf->coords.p1.x = i * fdf->step + fdf->coords.start.y;
			fdf->coords.p1.y = (j + 1) * fdf->step + fdf->coords.start.x;
			if (fdf->proj == 150)
			{
				iso(&fdf->coords.p0.x, &fdf->coords.p0.y);
				iso(&fdf->coords.p1.x, &fdf->coords.p1.y);
			}
			draw_line(fdf);
			j++;
		}
		i++;
	}
	return (0);
}

int		draw_map(t_struct *fdf)
{
	draw_vert(fdf);
	draw_hor(fdf);
	return (0);
}

int		draw_window(t_struct *fdf)
{
	int		bpp;
	int		s_l;
	int		end;
	
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "New window");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->img_pix = (int *)mlx_get_data_addr(fdf->img_ptr, &bpp, &s_l, &end);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
