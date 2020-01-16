/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:20:54 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/14 18:09:30 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_map(int key, t_struct *fdf)
{
	erase_image(fdf);
	if (key == 123)
		fdf->c.start.y -= 10;
	if (key == 124)
		fdf->c.start.y += 10;
	if (key == 125)
		fdf->c.start.x += 10;
	if (key == 126)
		fdf->c.start.x -= 10;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	menu_window(fdf);
}

void	zoom_map(int key, t_struct *fdf)
{
	erase_image(fdf);
	if (key == 88)
		fdf->step += 5;
	if (key == 86)
		if (fdf->step > 5)
			fdf->step -= 5;
	if (key == 91)
		fdf->high -= 0.1;
	if (key == 84)
		fdf->high += 0.1;
	if (fdf->high < 0.1)
		fdf->high = 0.1;
	else if (fdf->high > 10)
		fdf->high = 10;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);	
	menu_window(fdf);
}

void	change_projection(int key, t_struct *fdf)
{
	erase_image(fdf);
	// fdf->angle_x = 0;
	// fdf->angle_y = 0;
	// fdf->angle_z = 0;
	if (key == 87 && fdf->proj == 0)
		fdf->proj = 150;
	else
		fdf->proj = 0;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	menu_window(fdf);
}

void	rotate(int key, t_struct *fdf)
{
	erase_image(fdf);
	if (key == 65)
		fdf->angle_x += 0.05;
	if (key == 82)
		fdf->angle_x -= 0.05;
	if (key == 85)
		fdf->angle_y += 0.05;
	if (key == 83)
		fdf->angle_y -= 0.05;
	if (key == 92)
		fdf->angle_z += 0.05;
	if (key == 89)
		fdf->angle_z -= 0.05;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	menu_window(fdf);
}

int		key_press(int key, t_struct *fdf)
{
	if (!fdf || key == 53)
		exit(0);
	if (key >= 123 && key <= 126)
		move_map(key, fdf);
	if (key == 88 || key == 86 || key == 84 || key == 91)
		zoom_map(key, fdf);
	if (key == 87)
		change_projection(key, fdf);
	if (key == 65 || key == 82 || key == 83 || key == 85 || key == 89 || key == 92)
		rotate(key, fdf);
	return (0);
}
