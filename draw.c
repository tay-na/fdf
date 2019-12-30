/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:10:00 by tollivan          #+#    #+#             */
/*   Updated: 2019/12/27 17:58:05 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_struct *fdf, int x, int y)
{
	int		p;

	p = y * WIDTH + x;
	if (x >= MENU_W && x < WIDTH && y > 0 && y < HEIGHT)
		fdf->img_pix[p] = fdf->col; 
}

void	draw_line_bes(t_struct *fdf)
{
	int		x;
	int		y;
	int		err;
	int		err2;

	x = fdf->c.p0.x;
	y = fdf->c.p0.y;
	err = fdf->c.d.x - fdf->c.d.y;
	while (x != fdf->c.p1.x || y != fdf->c.p1.y)
	{
		put_pixel(fdf, x, y);
		err2 = err * 2;
		if (err2 > fdf->c.d.y * -1)
		{
			err = err - fdf->c.d.y;
			x = x + fdf->c.s.x;
		}
		if (err2 < fdf->c.d.x)
		{
			err = err + fdf->c.d.x;
			y = y + fdf->c.s.y;
		}
	}
	put_pixel(fdf, x, y);
}

void	draw_l(t_point p0, t_point p1, t_struct *fdf)
{
	fdf->c.d.x = abs(p1.x - p0.x);
	fdf->c.d.y = abs(p1.y - p0.y);
	fdf->c.s.x = p0.x < p1.x ? 1 : -1;
	fdf->c.s.y = p0.y < p1.y ? 1 : -1;
	draw_line_bes(fdf);
}

int		draw_map(t_struct *fdf)
{
	int		i;
	int		j;
	
	i = -1;
	while (++i < fdf->h)
	{
		j = -1;
		while (++j < fdf->w)
		{
			if (j != fdf->w - 1)
			{
				fdf->col = 0xffffff; //remove this line
				fdf->c.p0 = new_c(&(fdf->c.p0), j, i, fdf->map[i][j]);
				fdf->c.p1 = new_c(&(fdf->c.p1), j + 1, i, fdf->map[i][j + 1]);
				draw_l(change(&fdf->c.p0, fdf), change(&fdf->c.p1, fdf), fdf);
			}
			if (i != fdf->h - 1)
			{
				fdf->col = 0xFFC000; //remove this line
				fdf->c.p0 = new_c(&(fdf->c.p0), j, i, fdf->map[i][j]);
				fdf->c.p1 = new_c(&(fdf->c.p1), j, i + 1, fdf->map[i + 1][j]);
				draw_l(change(&fdf->c.p0, fdf), change(&fdf->c.p1, fdf), fdf);
			}
		}
	}
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
	menu_window(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
