#include "fdf.h"
#include "color.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

/* 
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
} */


void	color_gradient(int *color, int i, int j, t_struct *fdf)
{
	// static int	colors[5] = {INDIGO, TYRIAN_PURPLE, POMPADUR, HIPPIE_PINK, AMBER};
	double		percentage;

	percentage = percent(fdf->z_min, fdf->z_max, fdf->map[i][j]);
	if (fdf->col_count == 0)
	{
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
	if (fdf->col_count == 1)
	{
		if (percentage < 0.2)
			*color = TYRIAN_PURPLE;
		else if (percentage < 0.4)
			*color = POMPADUR;
		else if (percentage < 0.6)
			*color = HIPPIE_PINK;
		else if (percentage < 0.8)
			*color = AMBER;
		else if (percentage <= 1)
			*color = INDIGO;
	}
	if (fdf->col_count == 2)
	{
		if (percentage < 0.2)
			*color = POMPADUR;
		else if (percentage < 0.4)
			*color = HIPPIE_PINK;
		else if (percentage < 0.6)
			*color = AMBER;
		else if (percentage < 0.8)
			*color = INDIGO;
		else if (percentage <= 1)
			*color = TYRIAN_PURPLE;
	}
	if (fdf->col_count == 3)
	{
		if (percentage < 0.2)
			*color = HIPPIE_PINK;
		else if (percentage < 0.4)
			*color = AMBER;
		else if (percentage < 0.6)
			*color = INDIGO;
		else if (percentage < 0.8)
			*color = TYRIAN_PURPLE;
		else if (percentage <= 1)
			*color = POMPADUR;
	}
	if (fdf->col_count == 4)
	{
		if (percentage < 0.2)
			*color = AMBER;
		else if (percentage < 0.4)
			*color = INDIGO;
		else if (percentage < 0.6)
			*color = TYRIAN_PURPLE;
		else if (percentage < 0.8)
			*color = POMPADUR;
		else if (percentage <= 1)
			*color = HIPPIE_PINK;
	}
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(int x, int y, t_struct *fdf)
{
	int     red;
	int     green;
	int     blue;
	double  percentage;

	if (fdf->c.p0.col == fdf->c.p1.col)
		return (fdf->c.p0.col);
	if (fdf->c.d.x > fdf->c.d.y)
		percentage = percent(fdf->c.p0.x, fdf->c.p1.x, x);
	else
		percentage = percent(fdf->c.p0.y, fdf->c.p1.y, y);
	red = get_light((fdf->c.p0.col >> 16) & 0xFF, (fdf->c.p1.col >> 16) & 0xFF, percentage);
	green = get_light((fdf->c.p0.col >> 8) & 0xFF, (fdf->c.p1.col >> 8) & 0xFF, percentage);
	blue = get_light(fdf->c.p0.col & 0xFF, fdf->c.p1.col & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
