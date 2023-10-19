/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:33:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 21:28:15 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# include "libft/includes/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx/mlx.h"

# define WIN_WIDTH  800
# define WIN_HEIGHT 600

typedef enum s_start_pos
{
	NO = 0,
	SO,
	WE,
	EA
} e_start_pos;

typedef struct s_cmlx
{
	void			*ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bpp;
	int				line_length;
	int				endian;
}	t_cmlx;

typedef struct s_parse
{
	char	*line;
	char	*map_file;
	int		map_fd;
	char	**map;
	char	*ceiling;
	char	*floor;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_parse;

typedef struct s_data
{
	t_cmlx			*cmlx;
}	t_data;



# endif