/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:19:33 by tollivan          #+#    #+#             */
/*   Updated: 2019/12/23 15:26:38 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	erase_image(t_struct *fdf)
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

t_point	new_c(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
	return(*point);
}