/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:52:43 by tollivan          #+#    #+#             */
/*   Updated: 2019/12/17 16:33:39 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(ISO);
    *y = -z + (previous_x + previous_y) * sin(ISO);
}

void		rotate_x(int *y, int *z, t_struct *fdf)
{
	int		prev_y;
	
	prev_y = *y;
	*y = prev_y * cos(fdf->angle_x) + *z * sin(fdf->angle_x);
	*z = -prev_y * sin(fdf->angle_x) + *z * cos(fdf->angle_x);
}

void		rotate_y(int *x, int *z, t_struct *fdf)
{
	int		prev_x;
	
	prev_x = *x;
	*x = prev_x * cos(fdf->angle_y) + *z * sin(fdf->angle_y);
	*z = -prev_x * sin(fdf->angle_y) + *z * cos(fdf->angle_y);
}

void		rotate_z(int *x, int *y, t_struct *fdf)
{
	int		prev_x;
	int		prev_y;
	
	prev_y = *y;
	prev_x = *x;
	*y = prev_y * cos(fdf->angle_z) + prev_x * sin(fdf->angle_z);
	*x = -prev_y * sin(fdf->angle_z) + prev_x * cos(fdf->angle_z);
}

void	transform(int *x_0, int *y_0, int *x_1, int *y_1, int z_0, int z_1, t_struct *fdf)
{
	rotate_x(y_0, &z_0, fdf);
	rotate_x(y_1, &z_1, fdf);
	rotate_y(x_0, &z_0, fdf);
	rotate_y(x_1, &z_1, fdf);
	rotate_z(x_0, y_0, fdf);
	rotate_z(x_1, y_1, fdf);
	if (fdf->proj == 150)
	{
		iso(x_0, y_0, (z_0 * fdf->step));
		iso(x_1, y_1, (z_1 * fdf->step));
	}
}