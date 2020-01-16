/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:05:10 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/16 20:24:04 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

int		is_hex(char map_ch)
{
	if (ft_isdigit(map_ch) || ft_strchr(HEX, map_ch) != NULL)
		return (1);
	return (0);
}

int		get_width(/* t_struct *fdf, */ char *map_ch)
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
			// printf("c  %d\n", c);
			while ((map_ch[i] == ',' || is_hex(map_ch[i])))
			{
				i++;
				if (i == (int)ft_strlen(map_ch))
					break ;
			}
		}
		else
			i++;
		// printf("i  %d\n", i);
	}
// printf("%d\n", c);
	return (c);
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

void	get_colors(char *map_ch, int **color)
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
			// {
				i++;
				// if (i == (int)ft_strlen(map_ch))
					// break ;
			// }
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
           		// {
					i++;
					// if (i == (int)ft_strlen(map_ch))
						// break ;
				// }
			}
		}
		i++;
	// printf("i  %d\n", i);
	}
}

int		check_width(int	string, int width)
{
	if (width != string)
		return (1);
	return (0);
}

void	char_to_int(char *map_ch, int **map, int **color, t_struct *fdf)
{
	
	if (fdf->w == 0)
		fdf->w = get_width(/* fdf,  */map_ch);
	else
		if ((check_width(get_width(map_ch), fdf->w)) == 1)
			error(MAP_FORMAT);
	if (!(*map = (int *)ft_memalloc(sizeof(int) * fdf->w)))
		error(INIT);
	if (!(*color = (int *)ft_memalloc(sizeof(int) * fdf->w)))
		error(INIT);
	get_heights(map_ch, map);
	get_colors(map_ch, color);
}
/* 
static void		ft_free_ch(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}  */

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
		// printf("strlen[%d] %d   ", i, (int)ft_strlen(map_ch[i]));
		char_to_int(map_ch[i], &(fdf->map[i]), &(fdf->color[i]), fdf);
		// printf("int arr map_ch[%d]  %s\n", i, map_ch[i]);
		// printf("%d    %d  ", i, fdf->map[i][0]);
		// printf("%d  ", fdf->map[i][1]);
		// printf("%d  ", fdf->map[i][2]);
		// printf("%d  ", fdf->map[i][3]);
		// printf("%d  ", fdf->map[i][4]);
		// printf("%d  ", fdf->map[i][5]);
		// printf("%d  ", fdf->map[i][6]);
		// printf("%d  ", fdf->map[i][7]);
		// printf("%d  ", fdf->map[i][8]);
		// printf("%d  \n", fdf->map[i][9]);
		// printf("%d    %d  ", i, fdf->color[i][0]);
		// printf("%d  ", fdf->color[i][1]);
		// printf("%d  ", fdf->color[i][2]);
		// printf("%d  ", fdf->color[i][3]);
		// printf("%d  ", fdf->color[i][4]);
		// printf("%d  ", fdf->color[i][5]);
		// printf("%d  ", fdf->color[i][6]);
		// printf("%d  ", fdf->color[i][7]);
		// printf("%d  ", fdf->color[i][8]);
		// printf("%d  \n", fdf->color[i][9]);
		i++;
		// printf("\n");
	}
	// ft_free_ch(map_ch, fdf->h);
	return (0);
}


int		check_argv(char *argv)
{
	// char	*check;

	if (!(ft_strstr(argv, ".fdf")))
		return (1);
	/* else if (ft_strstr(ft_strstr(argv, ".fdf"), ".fdf"))
		return (1); */
	else
		return (0);	
}

int		read_map(char *argv, t_struct *fdf)//add returns
{
	char	**map_ch;
	int		fd;
	int		i;
	// int		j;
	char	*line;
	
	// fdf->h = 0;
	// fdf->w = 0;
	if (!(fd = open(argv, O_RDONLY)))
		error(FILE_READ);
	if ((get_next_line(fd, &line) == -1))
		error(FILE_READ);
	if (check_argv(argv) == 1)
		error(USAGE);
	i = 1;
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	// printf("fdf->h  %d\n", i);
	close(fd);
	if (!(fd = open(argv, O_RDONLY)))
		error(FILE_READ);
	fdf->h = i;
	if (!(map_ch = (char **)ft_memalloc(sizeof(char *) * (fdf->h + 1))))
		error(INIT);
	// printf("fdf->h   %d\n", fdf->h);
	i = 0;
	while (get_next_line(fd, &line))
	{
		map_ch[i] = ft_strdup(line);
		// printf("gnl map_ch[%d]  %s\n", i, map_ch[i]);
		free(line);
		// printf("i in  %d\n", i);
		i++;
	}
	// printf("i out %d\n", i);
	map_ch[i] = NULL;
	get_int_arr(fdf, map_ch);
	fdf->c.start.x = HEIGHT / 2;
	fdf->c.start.y = (WIDTH + MENU_W) / 2;
	// fdf->step = 30;
	// fdf->high = 1;
	return (1);
}
