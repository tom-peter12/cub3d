/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:33:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/24 20:49:32 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# include "libft/includes/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx/mlx.h"
# include "err.h"

# define WIN_WIDTH  800
# define WIN_HEIGHT 600

typedef enum s_map_dir
{
	NO = 0,
	SO,
	WE,
	EA,
	F,
	C
}	t_map_dir;

typedef enum s_start_pos
{
	N = 0,
	S,
	W,
	E
}	t_start_pos;

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

typedef struct s_file
{
	char 	*line;
	char	*map_file;
	int		fd;
	char	**file_cntnt;
	int		file_len;
}			t_file;

typedef struct s_valid_map
{
	char	**tab;
	size_t	height;
	size_t	width;
}			t_valid_map;

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
	int		*dup_check;
	int		map_height;
	int		map_width;
}			t_parse;



// typedef struct s_player
// {
// 	double	x;
// 	double	y;
// 	double	dir;
// }	t_player;

// typedef struct s_raytrace
// {
// 	int	ray;
// }	t_raytrace;

// init_deinit.c
int		ft_init_parse(t_parse *parse);
void	exit_return_freer(t_parse *parse);

typedef struct s_data
{
	t_cmlx			*cmlx;
}	t_data;

// parse_arg
int		ft_validate_cub(t_parse *parse);
int		ft_validate_args(t_parse *parse, int argc, char **argv);
int		ft_validate_parsed(t_parse *parse);

// parse_fill
void	ft_fill_map_parser(t_parse *parse, char *str);
int		ft_fill_parser(t_parse *parse);

// parse_utils
int		ft_is_dir(char *dir);
int		ft_check_file(char *path);
int		ft_isattr_dup(t_parse *parse, int dir);

// parse
int		ft_color_validate(char *str);
void	parser(t_parse *parse, int argc, char **argv);


int		ft_closed_map(t_parse *parse);

int		ft_init_valid_map(t_parse *parse, t_valid_map *map, int len);

#endif
