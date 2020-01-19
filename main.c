/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wife <wife@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:11:06 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/20 00:09:55 by wife             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"
/* 
static void		ft_free(int **s, int i)
{
	while (i > 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
} */


int		main(int argc, char **argv)
{
	t_struct	*fdf;
	
	errno = 0;
	if (argc != 2)
		error(USAGE);
	fdf = initialize();
	if (!(read_map(argv[1], fdf)))
		error(MAP_READ);
	draw_window(fdf);
	/* ft_free(fdf->map, fdf->h);
	ft_free(fdf->color, fdf->h);*/
	ft_memdel((void**)&fdf);
	exit(0);
	return (0);
}