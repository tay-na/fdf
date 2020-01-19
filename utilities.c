/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wife <wife@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:19:33 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/20 00:09:50 by wife             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

t_point	new_c(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
	return(*point);
}


int		is_hex(char map_ch)
{
	if (ft_isdigit(map_ch) || ft_strchr(HEX, map_ch) != NULL)
		return (1);
	return (0);
}

int		check_char(char s)
{
	int		res;

	res = 0;
	if (s >= '0' && s <= '9')
		res = s - '0';
	else if (s >= 'a' && s <= 'z')
		res = s - 'a' + 10;
	else if	(s >= 'A' && s <= 'Z')
		res = s - 'A' + 10;
	else
		res = -1;
	return (res);	
}

int		ft_atoi_base(char *str, int base)
{
	int	i;
	int	sign;
	int	nb;
	
	sign = 1;
	nb = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	i = check_char(*str);
	while (i >= 0 && i <= base)
	{
		nb = nb * base + i;
		str++;
		i = check_char(*str);
	}
	return (sign == 1 ? nb : -nb);
}

void	error(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);	
	exit (1);
}


static void		ft_free_ch(char **s)
{
	int		i = 0;
	
	while (s[i])
	{
		free(s[i]);
		// printf("i1   %d\n", i);
		i++;
	}
	free(s);
}