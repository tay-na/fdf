/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:05:10 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/24 19:37:00 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

void	check_validity(char *map_ch)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(map_ch))
	{
		if (is_hex(map_ch[i]) == 0 && map_ch[i] != ' ' && map_ch[i] != ',' &&
					map_ch[i] != '-')
			error(MAP_FORMAT);
		i++;
	}
}

void	char_to_int(char *map_ch, int **map, int **color, t_struct *fdf)
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
		check_validity(map_ch[i]);
		char_to_int(map_ch[i], &(fdf->map[i]), &(fdf->color[i]), fdf);
		i++;
	}
	height_extremum(fdf);
	ft_free_ch(map_ch);
	return (0);
}

void	check_argv_and_get_height(char *argv, t_struct *fdf)
{
	int		fd;
	char	*line;
	int		i;

	if (!(fd = open(argv, O_RDONLY)))
		error(FILE_READ);
	if ((get_next_line(fd, &line) == -1))
		error(FILE_READ);
	ft_strdel(&line);
	if (!(ft_strstr(argv, ".fdf")))
		error(USAGE);
	i = 1;
	while (get_next_line(fd, &line))
	{
		ft_strdel(&line);
		i++;
	}
	fdf->h = i;
	close(fd);
}

int		read_map(char *argv, t_struct *fdf)
{
	char	**map_ch;
	int		fd;
	int		i;
	char	*line;

	check_argv_and_get_height(argv, fdf);
	if (!(fd = open(argv, O_RDONLY)))
		error(FILE_READ);
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
	assign_color(fdf);
	return (1);
}
