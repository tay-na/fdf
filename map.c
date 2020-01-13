/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:05:10 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/13 19:44:42 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

int		is_hex(char map_ch)
{
	if (ft_isdigit(map_ch) || (ft_toupper(map_ch) >= 'A' && ft_toupper(map_ch <= 'F')))
		return (1);
	return (0);
}

void	get_width(t_struct *fdf, char *map_ch)
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
			while (map_ch[i] == ',' || map_ch[i] == 'x' || is_hex(map_ch[i]))
				i++;
		}
		else
			i++;
	}
	fdf->w = c;
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
			while (ft_isdigit(map_ch[i]) || map_ch[i] == ',' || map_ch[i] == 'x' || is_hex(map_ch[i]))
				i++;
		}
		else
			i++;
	}
}

void	get_colors(char *map_ch, int **color)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (++i < (int)ft_strlen(map_ch))
	{
		if (ft_isdigit(map_ch[i]))
		{
			while (ft_isdigit(map_ch[i]))
				i++;
			if (map_ch[i] == ' ' || map_ch[i] != ',')
			{
				(*color)[c] = 1;
				c++;
			}
		}
		if (map_ch[i] == ',')
		{
			if (map_ch[i + 1] == '0' && ft_toupper(map_ch[i + 2]) == 'X')
        	{
				i += 3;
        		(*color)[c] = ft_atoi_base(&map_ch[i], 16);
        		c++;
        		while (is_hex(map_ch[i]))
           			i++;
			}
		}
	}
}

void	char_to_int(char *map_ch, int **map, int **color, t_struct *fdf)
{
	if (fdf->w == 0)
		get_width(fdf, map_ch);
	if (!(*map = (int *)ft_memalloc(sizeof(int) * fdf->w)))
		error(INIT);
	if (!(*color = (int *)ft_memalloc(sizeof(int) * fdf->w)))
		error(INIT);
	get_heights(map_ch, map);
	get_colors(map_ch, color);
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

	if (!(fdf->map = (int **)ft_memalloc(sizeof(int *) * fdf->h)))
		error(INIT);
	if (!(fdf->color = (int **)ft_memalloc(sizeof(int *) * fdf->h)))
		error(INIT);
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
	
	fdf->h = 0;
	fdf->w = 0;
	i = 0;
	if (!(fd = open(argv, O_RDONLY)))
		error(FILE_READ);
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	close(fd);
	if (!(fd = open(argv, O_RDONLY)))
		error(FILE_READ);
	if (!(map_ch = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		error(INIT);
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
	fdf->c.start.x = HEIGHT / 2;
	fdf->c.start.y = (WIDTH + MENU_W) / 2;
	fdf->step = 30;
	fdf->high = 1;
	return (1);
}
