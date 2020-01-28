/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wife <wife@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:41:59 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/29 00:11:14 by wife             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

double	percent(int start, int end, int current, float kos)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return (placement / (distance + kos));
	// return ((distance == 0) ? 1.0 : (placement / distance));
}

int		color_check(int color)
{
	if (color == INDIGO || color == TYRIAN_PURPLE || color == POMPADUR ||
		color == HIPPIE_PINK || color == AMBER)
		return (1);
	else
		return (0);
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}
