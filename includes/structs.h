/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:24:59 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/12 19:25:53 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}			t_color;

typedef struct s_map
{
	char			**tab;
	t_color			*c_ceil;
	t_color			*c_floor;
	size_t			height;
	size_t			width;
}			t_map;

typedef struct s_parse
{
	char		*line;
	char		*map_file;
	int			map_fd;
	char		**map_tmp;
	char		**textures;
	int			*dup_check;
	int			map_height;
	int			map_width;
	t_map		*map;
}			t_parse;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

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

typedef struct s_fps
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}	t_fps;

typedef struct s_key
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
	int		up;
	int		down;
}	t_key;

typedef struct t_dda
{
	t_vector	side_dist;
	t_vector	delta_dist;
	t_vector	map;
	t_vector	step;
	double		wall_dist;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_dda;

typedef struct s_ray
{
	double		mnchi;
	t_vector	ray_vec;
	t_dda		dda;
}	t_ray;

typedef struct s_game
{
	t_parse			parse;
	t_fps			fps;
	t_cmlx			cmlx;
	t_key			key;
	t_ray			ray;
}	t_game;

#endif