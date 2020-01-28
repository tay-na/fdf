/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wife <wife@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:53:05 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/28 23:56:45 by wife             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

void	height_extremum(t_struct *fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fdf->h)
	{
		j = 0;
		while (j < fdf->w)
		{
			fdf->z_max = ft_ismax(fdf->map[i][j], fdf->z_max);
			j++;
		}
	}
	i = 0;
	while (i < fdf->h)
	{
		j = 0;
		while (j < fdf->w)
		{
			fdf->z_min = ft_ismin(fdf->map[i][j], fdf->z_min);
			party_parrot(&(fdf->color)[i][j], i, j, fdf);
			j++;
		}
		i++;
	}
}

void	get_colors(char *map_ch, int **color)
{
	int	i;
	int	c;

	i = -1;
	c = -1;
	while (++i < (int)ft_strlen(map_ch))
	{
		if (ft_isdigit(map_ch[i]))
		{
			while (ft_isdigit(map_ch[i]))
				i++;
			if (map_ch[i] == ' ' || map_ch[i] != ',')
				(*color)[++c] = 1;
		}
		if (map_ch[i] == ',')
		{
			if (map_ch[i + 1] == '0' && ft_toupper(map_ch[i + 2]) == 'X')
			{
				i += 3;
				(*color)[++c] = ft_atoi_base(&map_ch[i], 16);
				while (is_hex(map_ch[i]))
					i++;
			}
		}
	}
}

void	get_heights(char *map_ch, int **map)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
	while (i < (int)ft_strlen(map_ch))
	{
		if (ft_isdigit(map_ch[i]))
		{
			(*map)[h] = ft_atoi(&map_ch[i]);
			h++;
			while (map_ch[i] == ',' || is_hex(map_ch[i]))
			{
				i++;
				if (i == (int)ft_strlen(map_ch))
					break ;
			}
		}
		else
			i++;
	}
}

int		get_width(char *map_ch)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < (int)ft_strlen(map_ch))
	{
		if (ft_isdigit(map_ch[i]))
		{
			c++;
			while ((map_ch[i] == ',' || is_hex(map_ch[i])))
			{
				i++;
				if (i == (int)ft_strlen(map_ch))
					break ;
			}
		}
		else
			i++;
	}
	return (c);
}
