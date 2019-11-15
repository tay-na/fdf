/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:05:10 by tollivan          #+#    #+#             */
/*   Updated: 2019/11/15 20:52:37 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	char_to_int(char *map_ch, int *map, t_struct *fdf)
{
	int	i;
	int	c;

	(void)map;
	i = 0;
	c = 0;
	while(map_ch[i])
	{
		if (ft_isdigit(map_ch[i]))
		{
			c++;
			while (ft_isdigit(map_ch[i]))
				i++;
		}
		else
			i++;
	}
	fdf->w = c;
	map = (int *)ft_memalloc(sizeof(int) * c);
	i = 0;
	c = 0;
	while(map_ch[i])
	{
		if (ft_isdigit(map_ch[i]))
		{
			map[c] = ft_atoi(&map_ch[i]);
			printf("%d ", map[c]);
			c++;
			while (ft_isdigit(map_ch[i]))
				i++;
		}
		else
			i++;
	}
	printf("\n");
}

int		get_int_arr(t_struct *fdf, char **map_ch)
{
	int	i;

	fdf->map = (int **)ft_memalloc(sizeof(int *) * fdf->h);
	i = 0;
	while (map_ch[i])
	{
		char_to_int(map_ch[i], fdf->map[i], fdf);
		i++;
	}
	return (0);
}

int		read_map(char *argv, t_struct *fdf)//add returns
{
	char	**map_ch;
	int		fd;
	int		i;
	int		j;
	char	*line;
	
	i = 0;
	if (!(fd = open(argv, O_RDONLY)))
		return (-1);
	while (get_next_line(fd, &line))
		i++;
	close(fd);
	fd = open(argv, O_RDONLY);
	map_ch = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	fdf->h = i;
	j = 0;
	while (get_next_line(fd, &line))
	{
		map_ch[j] = ft_strdup(line);
		free(line);
		j++;
	}
	map_ch[j] = NULL;
	get_int_arr(fdf, map_ch);
	printf("check1");
	fdf->coords.start.x = 0;
	fdf->coords.start.y = 0;
	fdf->step = 50;
	return (1);
}
