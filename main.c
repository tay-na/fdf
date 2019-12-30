/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:11:06 by tollivan          #+#    #+#             */
/*   Updated: 2019/12/30 19:57:22 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_free(int **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

int		main(int argc, char **argv)
{
	t_struct	*fdf;
	
	if (argc != 2)
		return (-1);
	if (!(fdf = (t_struct *)ft_memalloc(sizeof(t_struct))))
		return (-1);
	if (!(read_map(argv[1], fdf)))
		return (-1);
	//printf("check2");
	//validation
	//draw_window(fdf);
	ft_free(fdf->map, fdf->h);
	ft_free(fdf->color, fdf->h);
	// free(fdf);
	free(fdf);
	exit(0);
	//printf("success");
	return (0);
}