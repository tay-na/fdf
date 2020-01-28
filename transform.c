/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wife <wife@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:52:43 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/28 22:42:53 by wife             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(ISO);
	*y = -z + (previous_x + previous_y) * sin(ISO);
}

void	rotate_x(int *y, int *z, t_struct *fdf)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(fdf->angle_x) + *z * sin(fdf->angle_x);
	*z = -prev_y * sin(fdf->angle_x) + *z * cos(fdf->angle_x);
}

void	rotate_y(int *x, int *z, t_struct *fdf)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(fdf->angle_y) + *z * sin(fdf->angle_y);
	*z = -prev_x * sin(fdf->angle_y) + *z * cos(fdf->angle_y);
}

void	rotate_z(int *x, int *y, t_struct *fdf)
{
	int	prev_x;
	int	prev_y;

	prev_y = *y;
	prev_x = *x;
	*y = prev_y * cos(fdf->angle_z) + prev_x * sin(fdf->angle_z);
	*x = -prev_y * sin(fdf->angle_z) + prev_x * cos(fdf->angle_z);
}

t_point	change(t_point *point, t_struct *fdf)
{
	point->x *= fdf->step;
	point->y *= fdf->step;
	point->z *= fdf->step / fdf->high;
	point->x -= (fdf->w * fdf->step) / 2;
	point->y -= (fdf->h * fdf->step) / 2;
	rotate_x(&point->y, &point->z, fdf);
	rotate_y(&point->x, &point->z, fdf);
	rotate_z(&point->x, &point->y, fdf);
	if (fdf->proj == 150)
		iso(&point->x, &point->y, point->z);
	point->x += fdf->c.start.y;
	point->y += fdf->c.start.x;
	return (*point);
}
