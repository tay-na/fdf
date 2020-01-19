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


int	get_default_color(int z, t_struct *fdf)
{
	double	percentage;

	percentage = percent(, map->z_max, z);
	if (percentage < 0.2)
		return (AMBER);
	else if (percentage < 0.4)
		return (HIPPIE_PINK);
	else if (percentage < 0.6)
		return (POMPADUR);
	else if (percentage < 0.8)
		return (TYRIAN_PURPLE);
	else
		return (INDIGO);
}


int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_point current, t_point start, t_point end, t_point delta)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (current.color == end.color)
        return (current.color);
    if (delta.x > delta.y)
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

void	assign_color(t_struct *fdf, int i, int j)
{
	if (fdf->color[i][j] == 1 || fdf->color[i][j] > 16777215 || fdf->color[i][j] < 0)
		fdf->col = 0xE06666;
	else
		fdf->col = fdf->color[i][j];
}