/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:19:33 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/24 19:18:11 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

t_point	new_c(t_point *point, int x, int y, t_struct *fdf)
{
	point->x = x;
	point->y = y;
	point->z = fdf->map[y][x];
	point->col = fdf->color[y][x];
	return (*point);
}

int		is_hex(char map_ch)
{
	if (ft_isdigit(map_ch) || ft_strchr(HEX, map_ch) != NULL)
		return (1);
	return (0);
}

void	error(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void	ft_free_ch(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
