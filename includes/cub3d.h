/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:33:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/07 17:46:59 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>


# if __APPLE__
	# include "mlx/mlx.h"
# elif __linux__
	# include "mlx_linux/mlx.h"
# endif
# include "libft/includes/libft.h"
# include "err.h"

# define WIN_WIDTH  1920
# define WIN_HEIGHT 1080
# define FOV 66.00
# define CUBE_SIZE 64.00
# define PI 3.141592653589
# define MOVE_SPEED 10
# define ROT_SPEED 0.3
// # define UNIT_VECTOR (i, j) (i / sqrt(i * i + j * j), j / sqrt(i * i + j * j))

# define A 		0
# define S 		1
# define D 		2
# define W		13
# define LEFT	123
# define RIGHT	124
# define DOWN	125
# define UP 	126
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
	t_vector pos;
	t_vector dir;
	t_vector plane;
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

// init_deinit.c
int		ft_init_parse(t_parse *parse);
void	exit_return_freer(t_parse *parse);


// parse_arg
int		ft_validate_cub(t_parse *parse);
int		ft_validate_args(t_parse *parse, int argc, char **argv);
int		ft_validate_parsed(t_parse *parse);

// parse_fill
void	ft_fill_map_parser(t_parse *parse);
int		ft_fill_parser(t_parse *parse);

// parse_utils
int		ft_is_dir(char *dir);
int		ft_check_file(char *path);
int		ft_isattr_dup(t_parse *parse, int dir);

// parse
int		ft_color_validate(char **str);
void	parser(t_parse *parse, int argc, char **argv);


int		ft_closed_map(t_parse *parse);

int		ft_init_valid_map(t_parse *parse, t_map *map, int len);

int		ft_texture_files(t_parse *parse);

#endif
