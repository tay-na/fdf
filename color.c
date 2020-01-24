/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:31:06 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/24 19:10:51 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"
#include "errors.h"

void	color_gradient(int *color, int i, int j, t_struct *fdf)
{
	double		percentage;

	percentage = percent(fdf->z_min, fdf->z_max, fdf->map[i][j]);
	if (*color == 1 && percentage < 0.2)
		*color = INDIGO;
	else if (*color == 1 && percentage < 0.4)
		*color = TYRIAN_PURPLE;
	else if (*color == 1 && percentage < 0.6)
		*color = POMPADUR;
	else if (*color == 1 && percentage < 0.8)
		*color = HIPPIE_PINK;
	else if (*color == 1 && percentage <= 1)
		*color = AMBER;
}

void	change_color(t_struct *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->h)
	{
		j = 0;
		while (j < fdf->w)
		{
			party_parrot(&(fdf->color)[i][j], i, j, fdf);
			j++;
		}
		i++;
	}
}

void	party_parrot(int *color, int i, int j, t_struct *fdf)
{
	static int	colors[5] = {INDIGO, TYRIAN_PURPLE, POMPADUR, HIPPIE_PINK,
							AMBER};
	int			index;
	double		quantil;

	quantil = percent(fdf->z_min, fdf->z_max, fdf->map[i][j]);
	index = (int)(floor(quantil * 5) + fdf->col_count) % 5;
	if (color_check(*color) && quantil < 0.2)
		*color = colors[index];
	else if (color_check(*color) && quantil < 0.4)
		*color = colors[index];
	else if (color_check(*color) && quantil < 0.6)
		*color = colors[index];
	else if (color_check(*color) && quantil < 0.8)
		*color = colors[index];
	else if (color_check(*color) && quantil <= 1)
		*color = colors[index];
}

int		get_color(int x, int y, t_struct *fdf)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (fdf->c.p0.col == fdf->c.p1.col)
		return (fdf->c.p0.col);
	if (fdf->c.d.x > fdf->c.d.y)
		percentage = percent(fdf->c.p0.x, fdf->c.p1.x, x);
	else
		percentage = percent(fdf->c.p0.y, fdf->c.p1.y, y);
	red = get_light((fdf->c.p0.col >> 16) & 0xFF,
					(fdf->c.p1.col >> 16) & 0xFF, percentage);
	green = get_light((fdf->c.p0.col >> 8) & 0xFF,
					(fdf->c.p1.col >> 8) & 0xFF, percentage);
	blue = get_light(fdf->c.p0.col & 0xFF,
					fdf->c.p1.col & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	assign_color(t_struct *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->h)
	{
		j = 0;
		while (j < fdf->w)
		{
			if (fdf->color[i][j] < 0 || fdf->color[i][j] > 16777215)
				error(COLOR_ERR);
			color_gradient(&(fdf->color)[i][j], i, j, fdf);
			j++;
		}
		i++;
	}
}
