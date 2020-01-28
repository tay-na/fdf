/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wife <wife@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:40:52 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/28 22:44:53 by wife             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "window_menu.h"
#include "errors.h"

t_struct	*initialize(void)
{
	t_struct	*fdf;

	if (!(fdf = (t_struct *)ft_memalloc(sizeof(t_struct))))
		error(INIT);
	fdf->w = 0;
	fdf->h = 0;
	fdf->high = 1;
	fdf->step = 30;
	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
	fdf->col = 0xFFFFFF;
	fdf->proj = 0;
	fdf->z_min = 0;
	fdf->z_max = 0;
	fdf->col_count = 0;
	fdf->c.start.x = HEIGHT / 2;
	fdf->c.start.y = (WIDTH + MENU_W) / 2;
	return (fdf);
}

void		erase_image(t_struct *fdf)
{
	int		i;

	i = 0;
	while (i < (HEIGHT * WIDTH - 1))
	{
		fdf->img_pix[i] = 0x000000;
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

void		menu_window(t_struct *fdf)
{
	int		y;

	y = -1;
	fdf->col = 0xFFE185;
	while (y++ <= HEIGHT)
		fdf->img_pix[y * WIDTH + MENU_W] = fdf->col;
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 200, 50, fdf->col, HOW_TO);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 100, fdf->col, MOVE);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 150, fdf->col, L_R);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 180, fdf->col, U_D);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 230, fdf->col, PROJ);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 280, fdf->col, PROJ_CH);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 330, fdf->col, FLAT);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 380, fdf->col, CONVEX);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 430, fdf->col, Z_AX);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 480, fdf->col, Z_L_R);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 530, fdf->col, Y_AX);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 580, fdf->col, Y_L_R);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 630, fdf->col, X_AX);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 680, fdf->col, X_L_R);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 730, fdf->col, RESET);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 780, fdf->col, RESET_CH);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 830, fdf->col, PARTY_P);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 880, fdf->col, P_PARROT);
}

// int			key_press(int key, t_struct *fdf)
// {
// 	if (!fdf || key == 53)
// 		exit(0);
// 	if (key >= 123 && key <= 126)
// 		move_map(key, fdf);
// 	if (key == 69 || key == 78 || key == 84 || key == 91)
// 		zoom_map(key, fdf);
// 	if (key == 87)
// 		change_projection(key, fdf);
// 	if (key == 88 || key == 86 || key == 83 || key == 85 ||
// 		key == 89 || key == 92)
// 		rotate(key, fdf);
// 	if (key == 82 || key == 67)
// 		restore(key, fdf);
// 	return (0);
// }
