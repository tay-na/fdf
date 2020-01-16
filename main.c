/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:11:06 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/16 20:03:21 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

/* static void		ft_free(int **s, int i)
{
	printf("%d\n", i);
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
} */

t_struct	*initialize(void)
{
	t_struct	*fdf;

	if (!(fdf = (t_struct *)ft_memalloc(sizeof(t_struct))))
		error(INIT);
	fdf->w = 0;
	fdf->h = 0;
	fdf->high = 1;
	fdf->step = 30;
	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
	fdf->col = 0xFFFFFF;
	fdf->proj = 0;
	return (fdf);
}

int		main(int argc, char **argv)
{
	t_struct	*fdf;
	
	errno = 0;
	if (argc != 2)
		error(USAGE);
	fdf = initialize();
	if (!(read_map(argv[1], fdf)))
		error(MAP_READ);
	//validation
	draw_window(fdf);
	
	// ft_free(fdf->map, fdf->h);
	// ft_free(fdf->color, fdf->h);
	// free(fdf);
	exit(0);
	return (0);
}