/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:11:06 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/24 19:12:35 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

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
	ft_memdel((void**)&fdf);
	exit(0);
	return (0);
}
