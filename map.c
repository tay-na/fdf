/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:05:10 by tollivan          #+#    #+#             */
/*   Updated: 2019/12/30 19:48:57 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	char_to_int(char *map_ch, int **map, int **color, t_struct *fdf)
{
	int	i;
	int	c;
	int f;

	i = 0;
	c = 0;
	while(map_ch[i])
	{
		if (ft_isdigit(map_ch[i]))
		{
			c++;
			while (map_ch[i] == ',' || map_ch[i] == 'x' || ft_isdigit(map_ch[i]) || (ft_toupper(map_ch[i]) >= 'A' && ft_toupper(map_ch[i]) <= 'F'))
				i++;
		}
		else
			i++;
	}
	fdf->w = c;
	printf("w   %d \n", fdf->w);
	*map = (int *)ft_memalloc(sizeof(int) * fdf->w);
	*color = (int *)ft_memalloc(sizeof(int) * fdf->w);
	i = 0;
	c = 0;
	f = 0;
	while(map_ch[i])
	{
		if (ft_isdigit(map_ch[i]))
		{
			(*map)[c] = ft_atoi(&map_ch[i]);
			c++;
			while (ft_isdigit(map_ch[i]))
				i++;
		}
		if (map_ch[i] == ',')
		{
       		if (map_ch[i + 1] == '0' && map_ch[i + 2] == 'x')
        	{
				i += 3;
        		(*color)[f] = ft_atoi_base(&map_ch[i], 16);
        		f++;
        		while (ft_isdigit(map_ch[i]) || (ft_toupper(map_ch[i]) >= 'A' && ft_toupper(map_ch[i]) <= 'F'))
           			i++;
			}
 		}
		else if (map_ch[i] != ',')
		{
			(*color)[f] = 1;
       		f++;
		}
		i++;
	}
}

static void		ft_free_ch(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

int		get_int_arr(t_struct *fdf, char **map_ch)
{
	int	i;

	fdf->map = (int **)ft_memalloc(sizeof(int *) * fdf->h);
	fdf->color = (int **)ft_memalloc(sizeof(int *) * fdf->h);
	i = 0;
	while (i < fdf->h)
	{
		char_to_int(map_ch[i], &(fdf->map[i]), &(fdf->color[i]), fdf);
		i++;
	}
	ft_free_ch(map_ch, fdf->h);
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
	{
		i++;
		free(line);
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	if (!(map_ch = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (-1);
	fdf->h = i;
	printf("h   %d \n", fdf->h);
	j = 0;
	while (get_next_line(fd, &line))
	{
		map_ch[j] = ft_strdup(line);
		free(line);
		j++;
	}
	map_ch[j] = NULL;
	get_int_arr(fdf, map_ch);
	fdf->c.start.x = HEIGHT / 2;
	fdf->c.start.y = (WIDTH + MENU_W) / 2;
	fdf->step = 30;
	fdf->high = 1;
	return (1);
}
