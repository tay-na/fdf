/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wife <wife@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:20:54 by tollivan          #+#    #+#             */
/*   Updated: 2019/12/04 21:26:59 by wife             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_map(int key, t_struct *fdf)
{
	erase_image(fdf);
	if (key == 106)
		fdf->coords.start.y -= 10;
	if (key == 108)
		fdf->coords.start.y += 10;
	if (key == 107)
		fdf->coords.start.x += 10;
	if (key == 105)
		fdf->coords.start.x -= 10;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

void	zoom_map(int key, t_struct *fdf)
{
	erase_image(fdf);
	if (key == 100)
		fdf->step += 5;
	if (key == 97)
		fdf->step -= 5;
	if (key == 119)
		fdf->high += 5;
	if (key == 120)
		fdf->high -= 5;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);	
}

void	change_projection(int key, t_struct *fdf)
{
	erase_image(fdf);
	if (key == 115 && fdf->proj == 0)
		fdf->proj = 150;
	else
		fdf->proj = 0;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

int		key_press(int key, t_struct *fdf)
{
	if (!fdf || key == 49)
		exit(0);
	if (key >= 105 && key <= 108)
		move_map(key, fdf);
	if (key == 97 || key == 100 || key == 119 || key == 120)
		zoom_map(key, fdf);
	if (key == 115)
		change_projection(key, fdf);
	return (0);
}
