/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:20:54 by tollivan          #+#    #+#             */
/*   Updated: 2019/11/15 20:50:28 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_map(int key, t_struct *fdf)
{
	erase_image(fdf);
	if (key == 123)
		fdf->coords.start.y -= 10;
	if (key == 124)
		fdf->coords.start.y += 10;
	if (key == 125)
		fdf->coords.start.x += 10;
	if (key == 126)
		fdf->coords.start.x -= 10;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

void	zoom_map(int key, t_struct *fdf)
{
	erase_image(fdf);
	if (key == 88)
		fdf->step += 5;
	if (key == 86)
		fdf->step -= 5;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);	
}

int		key_press(int key, t_struct *fdf)
{
	if (!fdf || key == 53)
		exit(0);
	if (key >= 123 && key <= 126)
		move_map(key, fdf);
	if (key == 88 || key == 86)
		zoom_map(key, fdf);
	return (0);
}