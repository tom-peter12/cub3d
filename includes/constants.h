/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:23:43 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/12 19:24:38 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define WIN_WIDTH  1920
# define WIN_HEIGHT 1080
# define FOV 66.00
# define CUBE_SIZE 64.00
# define PI 3.141592653589
# define MOVE_SPEED 10
# define ROT_SPEED 0.1

# define A 		0
# define S 		1
# define D 		2
# define W		13
# define LEFT	123
# define RIGHT	124
# define ESC	53

# define BLUE  0x0000FF
# define RED   0xFF0000
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF
# define BLACK 0x000000

typedef enum s_dir
{
	NO = 0,
	SO,
	WE,
	EA
}	t_dir;

#endif