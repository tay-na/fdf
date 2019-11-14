/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:10:00 by tollivan          #+#    #+#             */
/*   Updated: 2019/11/14 19:57:45 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_struct *fdf, int x, int y)
{
	int		p;

	p = y * 1000 + x;
	fdf->img_pix[p] = fdf->col; 
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
	fdf->step = 20;
	while (i < fdf->h)
	{
		j = 0;
		while (j < fdf->w - 1)
		{
			fdf->coords.p0.y = i * fdf->step;
			fdf->coords.p0.x = j * fdf->step;
			fdf->coords.p1.y = i * fdf->step;
			fdf->coords.p1.x = (j + 1) * fdf->step;
			// rotate_points();
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
	fdf->step = 20;
	while (i < fdf->w)
	{
		j = 0;
		while (j < fdf->h - 1)
		{
			fdf->coords.p0.x = i * fdf->step;
			fdf->coords.p0.y = j * fdf->step;
			fdf->coords.p1.x = i * fdf->step;
			fdf->coords.p1.y = (j + 1) * fdf->step;
			// rotate_points();
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

int		deal_key(int key, void *param)
{
	if (!param || key == 53)
		exit(0);
	return (0);
}

int		draw_window(t_struct *fdf)
{
	int		bpp;
	int		s_l;
	int		end;
	
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "New window");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 1000, 1000);
	fdf->img_pix = (int *)mlx_get_data_addr(fdf->img_ptr, &bpp, &s_l, &end);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 50, 50);
	mlx_key_hook(fdf->win_ptr, deal_key, (void *)0);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
