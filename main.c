/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:11:06 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/13 19:42:05 by tollivan         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_struct	*fdf;
	
	errno = 0;
	if (argc != 2)
		error(USAGE);
	if (!(fdf = (t_struct *)ft_memalloc(sizeof(t_struct))))
		error(INIT);
	if (!(read_map(argv[1], fdf)))
		error(MAP_READ);
	//validation
	draw_window(fdf);
	
	// ft_free(fdf->map, fdf->h);
	// ft_free(fdf->color, fdf->h);
	free(fdf);
	exit(0);
	return (0);
}