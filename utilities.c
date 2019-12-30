/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:19:33 by tollivan          #+#    #+#             */
/*   Updated: 2019/12/30 15:19:49 by tollivan         ###   ########.fr       */
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

int		check_char(char s)
{
	int		res;

	res = 0;
	if (s >= '0' && s <= '9')
		res = s - '0';
	else if (s >= 'a' && s <= 'z')
		res = s - 'a' + 10;
	else if	(s >= 'A' && s <= 'Z')
		res = s - 'A' + 10;
	else
		res = -1;
	return (res);	
}
/* 
int		check_base(char *str)
{
	int	i;
	int	base;

	i = 0;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')
		
}
 */
int		ft_atoi_base(char *str, int base)
{
	int	i;
	int	sign;
	int	nb;
	
	sign = 1;
	nb = 0;
	while (ft_isspace(str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	i = check_char(*str);
	while (i >= 0 && i <= base)
	{
		nb = nb * base + i;
		//printf("AB  %d ", nb);
		str++;
		i = check_char(*str);
	}
//	printf("\n");
	return (sign == 1 ? nb : -nb);
}

void		menu_window(t_struct *fdf)
{
	int		y;
	
	y = -1;
	fdf->col = 0xdeeeff;
	while (y++ <= HEIGHT)
		put_pixel(fdf, MENU_W, y);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 200, 50, fdf->col, "How to use:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 100, fdf->col, "Move:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 150, fdf->col, "Left / Right: left arrow / right arrow");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 180, fdf->col, "Up / Down:    up arrow / down arrow");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 230, fdf->col, "Projection:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 280, fdf->col, "Change:		 NumPad 5");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 330, fdf->col, "Flatten:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 380, fdf->col, "More / Less:  NumPad 2 / NumPad 8");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 430, fdf->col, "Rotate Z-axis:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 480, fdf->col, "Left / Right: NumPad 7 / NumPad 9");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 530, fdf->col, "Rotate Y-axis:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 580, fdf->col, "Left / Right: NumPad 1 / NumPad 3");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 630, fdf->col, "Rotate X-axis:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 680, fdf->col, "Left / Right: NumPad 0 / NumPad .");
}
