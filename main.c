/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:11:06 by tollivan          #+#    #+#             */
/*   Updated: 2019/11/14 17:52:22 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_struct	*fdf;
	
	if (argc != 2)
		return (-1);
	if (!(fdf = (t_struct *)ft_memalloc(sizeof(t_struct))))
		return (-1);
	if (!(read_map(argv[1], fdf)))
		return (-1);
	printf("check2");
	//validation
	draw_window(fdf);
	printf("success");
	return (0);
}