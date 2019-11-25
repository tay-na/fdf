/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:05:10 by tollivan          #+#    #+#             */
/*   Updated: 2019/11/25 20:16:41 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	char_to_int(char *map_ch, int **map, t_struct *fdf)
{
	int	i;
	int	c;

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
	*map = (int *)ft_memalloc(sizeof(int) * c);
	i = 0;
	c = 0;
	while(map_ch[i])
	{
		if (ft_isdigit(map_ch[i]))
		{
			(*map)[c] = ft_atoi(&map_ch[i]);
			//  printf("%d ", (*map)[c]);
			c++;
			while (ft_isdigit(map_ch[i]))
				i++;
		}
		else
			i++;
	}
	// printf("\n");
}

int		get_int_arr(t_struct *fdf, char **map_ch)
{
	int	i;

	fdf->map = (int **)ft_memalloc(sizeof(int *) * fdf->h);
	i = 0;
	while (map_ch[i])
	{
		printf("privet   ");
		char_to_int(map_ch[i], &(fdf->map[i]), fdf);
		printf("%d   ", fdf->map[i][0]);
		printf("%d   ", fdf->map[i][1]);
		printf("%d   ", fdf->map[i][2]);
		printf("%d   ", fdf->map[i][3]);
		printf("%d   ", fdf->map[i][4]);
		printf("%d   ", fdf->map[i][5]);
		printf("%d   ", fdf->map[i][6]);
		printf("%d   ", fdf->map[i][7]);
		printf("%d   ", fdf->map[i][8]);
		printf("%d   ", fdf->map[i][9]);
		printf("%d\n", fdf->map[i][10]);
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
	fdf->coords.start.x = 400;
	fdf->coords.start.y = 400;
	fdf->step = 50;
	return (1);
}
