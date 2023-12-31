/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:33:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/28 20:52:13 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# if __APPLE__
#  include "mlx/mlx.h"
# elif __linux__
#  include "mlx_linux/mlx.h"
# endif
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# include "libft/includes/libft.h"
# include "err.h"
# include "constants.h"
# include "structs.h"

// init_deinit.c
int		ft_init_parse(t_parse *parse);
void	exit_return_freer(t_parse *parse, int flag);

// parse_arg
int		ft_validate_cub(t_parse *parse);
int		ft_validate_args(t_parse *parse, int argc, char **argv);
int		ft_validate_parsed(t_parse *parse);

// parse_fill.c
void	ft_map_dimension(t_parse *parse);
int		ft_fill_attributes(t_parse *parse);
void	ft_texture_filler(t_parse *parse, t_trims *trims);
void	check_and_save_path(t_parse *parse, t_trims *trims, int index);
int		ft_fill_parser(t_parse *parse);

// parse_fill_2.c
void	ft_fill_map_parser(t_parse *parse, char **tmp_to_free, int *mapline);
int		is_defo_map_line(char *str);
int		ft_comma_check(char *str);
int		color_fill(t_parse *parse, char **color, char *c_f);
int		ft_ceiling_floor(t_parse *parse, char *c_f);

// parse_utils.c
int		ft_is_dir(char *dir);
int		ft_check_file(char *path);
int		ft_isattr_dup(t_parse *parse, int dir);
int		white_space(char *str);

int		ft_check_up_down(t_map *map, size_t j,
			ssize_t *down, ssize_t *up);

// parse
int		ft_color_validate(char **str);
void	parser(t_parse *parse, int argc, char **argv);

int		ft_closed_map(t_parse *parse);

int		ft_init_valid_map(t_parse *parse, t_map *map, int len);

int		ft_texture_files(t_parse *parse);

char	*ft_strrtrim(char const *s1, char const *set);

void	fill_arr_file(char *map_file, t_parse *parse);
/**
 * Ray casting files
 * 
 * raycasting.c
 * movement.c
 * dda_algo.c
 * r3nd3r.c
 * locating_player.c
 * utils.c 
*/

// raycasting.c
int		kaboom(void *param);
void	raycast(t_game *game, int i);
void	ray_vector_dir(t_game *game);

// movement.c
void	da_movement_thang(t_game *game);
void	rotation_movement(t_game *game);
void	left_right_movement(t_game *game);
void	front_back_movement(t_game *game);

// movement_utils.c
void	right_rotation(t_game *game);
void	left_rotation(t_game *game);

// dda_algo.c
void	pre_dda(t_game *game);
void	dda(t_game *game);
void	calculate_line_height(t_game *game);
void	calculate_draw_start_end(t_game *game);

// r3nd3r.c
void	draw_stripe(t_game *game, int i);

// init.c
void	init_keys(t_game *game);
int		init_game(t_game *game);
int		init_mlx(t_game *game);

// locating_player.c
void	ft_spawn_player_EW(t_game *game, char *str);
void	ft_spawn_player(t_game *game, char *str);
void	ft_locate_player(t_game *game);

// utils.c
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		clr_rgb(t_color *color);
int		close_window(t_game *game);

/**
 * 		Texture Mapping files
 *  r3nd3r_t3xtur3.c
 *  r3nd3r.c
 * 
*/

// r3nd3r_t3xtur3.c
void	texture_rendering(t_game *game, int i);
void	pre_texture_mapping(t_game *game);
void	texture_addr(t_game *game);
void	tex_which_side(t_game *game);

// r3nd3r.c
void	render(t_game *game, int i);
void	render_ceiling_floor(t_game *game, int i);

int		follow_mouse(int x, int y, t_game *game);
void	minimap2d(t_game *game);
#endif
