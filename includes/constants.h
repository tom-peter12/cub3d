/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:23:43 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/19 20:21:59 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define MOVE_WEIGHT 0.07
# define ROT_WEIGHT 0.04

# if __APPLE__
#  define WIN_WIDTH  1920
#  define WIN_HEIGHT 1080
#  define A 		0
#  define S 		1
#  define D 		2
#  define W			13
#  define LEFT		123
#  define RIGHT		124
#  define ESC		53

# elif __linux__
#  define WIN_WIDTH  800
#  define WIN_HEIGHT 600
#  define A 		97
#  define S			115
#  define D			100
#  define W			119
#  define LEFT		65361
#  define RIGHT		65363
#  define ESC		65307
# endif

#endif