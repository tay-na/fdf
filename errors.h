/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:28:53 by tollivan          #+#    #+#             */
/*   Updated: 2020/01/24 19:23:17 by tollivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <errno.h>

# define USAGE "Usage: ./fdf *.fdf"
# define MAP_READ "Map read error"
# define INIT "Initialisation error"
# define FILE_READ "File read error"
# define MAP_FORMAT "Incorrect map format"
# define COLOR_ERR "Incorrect color value"

#endif
