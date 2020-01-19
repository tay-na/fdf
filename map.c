/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wife <wife@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:05:10 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/20 00:09:46 by wife             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"


int		get_width(char *map_ch) /* 21 lines*/
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

void	get_heights(char *map_ch, int **map) /* 21 lines*/
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

void	get_colors(char *map_ch, int **color) /* 31 lines*/
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < (int)ft_strlen(map_ch))
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
		i++;
	}
}
/*
int		check_width(int	string, int width)
{
	if (width != string)
		return (1);
	return (0);
}
*/
void	char_to_int(char *map_ch, int **map, int **color, t_struct *fdf) /* 17 lines */
{
	int		width;

	width = 0;
	if (fdf->w == 0)
		fdf->w = get_width(map_ch);
	else
	{
		width = get_width(map_ch);
		if (width != fdf->w)
			error(MAP_FORMAT);
	}
		// if ((check_width(get_width(map_ch), fdf->w)) == 1)
		// 	error(MAP_FORMAT);
	if (!(*map = (int *)ft_memalloc(sizeof(int) * fdf->w)))
		error(INIT);
	if (!(*color = (int *)ft_memalloc(sizeof(int) * fdf->w)))
		error(INIT);
	get_heights(map_ch, map);
	get_colors(map_ch, color);
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
	ft_free_ch(map_ch);
	return (0);
}


int		check_argv(char *argv)
{
	if (!(ft_strstr(argv, ".fdf")))
		return (1);
	else
		return (0);	
}

int		read_map(char *argv, t_struct *fdf)
{
	char	**map_ch;
	int		fd;
	int		i;
	char	*line;
	
	if (!(fd = open(argv, O_RDONLY)))
		error(FILE_READ);
	if ((get_next_line(fd, &line) == -1))
		error(FILE_READ);
	ft_strdel(&line);
	if (check_argv(argv) == 1)
		error(USAGE);
	i = 1;
	while (get_next_line(fd, &line))
	{
		ft_strdel(&line);
		i++;
	}
	close(fd);
	if (!(fd = open(argv, O_RDONLY)))
		error(FILE_READ);
	fdf->h = i;
	if (!(map_ch = (char **)ft_memalloc(sizeof(char *) * (fdf->h + 1))))
		error(INIT);
	i = 0;
	while (get_next_line(fd, &line))
	{
		map_ch[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	map_ch[i] = NULL;
	get_int_arr(fdf, map_ch);
	fdf->c.start.x = HEIGHT / 2;
	fdf->c.start.y = (WIDTH + MENU_W) / 2;
	return (1);
}
