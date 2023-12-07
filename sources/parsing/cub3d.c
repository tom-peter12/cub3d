/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/07 20:00:50 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_mlx(t_game *game)
{
	game->cmlx.ptr = mlx_init();
	if (!game->cmlx.ptr)
		return (1);
	game->cmlx.img = mlx_new_image(game->cmlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	game->cmlx.mlx_win = mlx_new_window(game->cmlx.ptr, WIN_WIDTH, WIN_HEIGHT,
			"Wolfe... Nah cub3D");
	game->cmlx.addr = (int *)mlx_get_data_addr(game->cmlx.img, &(game->cmlx.bpp),
			&(game->cmlx.line_length), &(game->cmlx.endian));
	return (0);
}

void	ft_locate_player(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < (int)game->parse.map->height)
	{
		j = 0;
		while (j < (int)game->parse.map->width)
		{
			if (game->parse.map->tab[i][j] == 'N' ||
				game->parse.map->tab[i][j] == 'S' ||
				game->parse.map->tab[i][j] == 'E' ||
				game->parse.map->tab[i][j] == 'W')
			{
				game->fps.pos.x = j;
				game->fps.pos.y = i + 1;
				if (game->parse.map->tab[i][j] == 'N')
				{
					game->fps.dir.x = 0;
					game->fps.dir.y = 1;
				}
				else if (game->parse.map->tab[i][j] == 'S')
				{
					
					game->fps.dir.x = 0;
					game->fps.dir.y = -1;
				}
				else if (game->parse.map->tab[i][j] == 'E')
				{
					game->fps.dir.x = 1;
					game->fps.dir.y = 0;
				}
				else if (game->parse.map->tab[i][j] == 'W')
				{
					game->fps.dir.x = -1;
					game->fps.dir.y = 0;
				}
			}
			j++;
		}
		i++;
	}
}

int	init_keys(t_game *game)
{
	game->key.a = -1;
	game->key.s = -1;
	game->key.d = -1;
	game->key.w = -1;
	game->key.left = -1;
	game->key.right = -1;
	game->key.down = -1;
	game->key.up = -1;
	return (0);
}

int	init_player(t_game *game)
{
	ft_locate_player(game);
	
	return (0);
}

int	init_game(t_game *game)
{
	if (init_mlx(game))
		return (1);
	if (init_keys(game))
		return (1);
	if (init_player(game))
		return (1);
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->cmlx.ptr, game->cmlx.mlx_win);
	exit_return_freer(&game->parse);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->key.w = 1;
	if (keycode == A)
		game->key.a = 1;
	if (keycode == S)
		game->key.s = 1;
	if (keycode == D)
		game->key.d = 1;
	if (keycode == LEFT)
		game->key.left = 1;
	if (keycode == RIGHT)
		game->key.right = 1;
	if (keycode == UP)
		game->key.up = 1;
	if (keycode == DOWN)
		game->key.down = 1;
	if (keycode == ESC)
		close_window(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->key.w = -1;
	if (keycode == A)
		game->key.a = -1;
	if (keycode == S)
		game->key.s = -1;
	if (keycode == D)
		game->key.d = -1;
	if (keycode == LEFT)
		game->key.left = -1;
	if (keycode == RIGHT)
		game->key.right = -1;
	if (keycode == UP)
		game->key.up = -1;
	if (keycode == DOWN)
		game->key.down = -1;
	return (0);
}

void	pre_dda(t_game *game)
{
	game->ray.dda.map.x = (int)game->fps.pos.x;
	game->ray.dda.map.y = (int)game->fps.pos.y;
	game->ray.dda.delta_dist.x = 1e30;
	if (game->ray.ray_vec.x != 0)
		game->ray.dda.delta_dist.x = fabs(1.0 / game->ray.ray_vec.x);
	game->ray.dda.delta_dist.y = 1e30;
	if (game->ray.ray_vec.y != 0)
		game->ray.dda.delta_dist.y = fabs(1.0 / game->ray.ray_vec.y);
	game->ray.dda.hit = 0;
	if (game->ray.ray_vec.x < 0)
	{
		game->ray.dda.step.x = -1;
		game->ray.dda.side_dist.x = (game->fps.pos.x - game->ray.dda.map.x) * game->ray.dda.delta_dist.x;
	}
	else
	{
		game->ray.dda.step.x = 1;
		game->ray.dda.side_dist.x = (game->ray.dda.map.x + 1.0 - game->fps.pos.x) * game->ray.dda.delta_dist.x;
	}
	if (game->ray.ray_vec.y < 0)
	{
		game->ray.dda.step.y = -1;
		game->ray.dda.side_dist.y = (game->fps.pos.y - game->ray.dda.map.y) * game->ray.dda.delta_dist.y;
	}
	else
	{
		game->ray.dda.step.y = 1;
		game->ray.dda.side_dist.y =(game->ray.dda.map.y + 1.0 - game->fps.pos.y) * game->ray.dda.delta_dist.y;
	}
}


void dda(t_game *game) {
	pre_dda(game);
    while (game->ray.dda.hit == 0)
	{
        if (game->ray.dda.side_dist.x < game->ray.dda.side_dist.y)
		{
            game->ray.dda.side_dist.x += game->ray.dda.delta_dist.x;
            game->ray.dda.map.x += game->ray.dda.step.x;
			game->ray.dda.side = 0;
        }
		else
		{
            game->ray.dda.side_dist.y += game->ray.dda.delta_dist.y;
            game->ray.dda.map.y += game->ray.dda.step.y;
			game->ray.dda.side = 1;
        }
		if (game->parse.map->tab[(int)game->ray.dda.map.y][(int)game->ray.dda.map.x] == '1')
			game->ray.dda.hit = 1;
    }
}


int	create_rgb(t_color *color)
{
	return (color->r << 16 | color->g << 8 | color->b);
}

void	draw_stripe(t_game *game, int i)
{
	int		j;

	j = 0;
	while (j < game->ray.dda.draw_start)
	{
		game->cmlx.addr[j * WIN_WIDTH + i] = create_rgb(game->parse.map->c_ceil);
		j++;
	}
	while (j < game->ray.dda.draw_end)
	{
		if (game->ray.dda.side == 0)
		{
			if (game->ray.dda.step.x == -1)
				game->cmlx.addr[j * WIN_WIDTH + i] = WHITE;
		}
		else
		{
			if (game->ray.dda.step.y == -1)
				game->cmlx.addr[j * WIN_WIDTH + i] = RED;
			else if (game->ray.dda.step.y == 1)
				game->cmlx.addr[j * WIN_WIDTH + i] = BLACK;
			else if (game->ray.dda.step.x == -1)
				game->cmlx.addr[j * WIN_WIDTH + i] = RED;
			else
				game->cmlx.addr[j * WIN_WIDTH + i] = WHITE;
		}
		j++;
	}
	while (j < WIN_HEIGHT)
	{
		game->cmlx.addr[j * WIN_WIDTH + i] = create_rgb(game->parse.map->c_floor);
		j++;
	}
}

void	calculate_draw_start_end(t_game *game)
{
	game->ray.dda.draw_start = -game->ray.dda.line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray.dda.draw_start < 0)
		game->ray.dda.draw_start = 0;
	game->ray.dda.draw_end = game->ray.dda.line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray.dda.draw_end >= WIN_HEIGHT)
		game->ray.dda.draw_end = WIN_HEIGHT - 1;
}

void	calculate_line_height(t_game *game)
{
	if (game->ray.dda.side == 0)
		game->ray.dda.wall_dist = (game->ray.dda.map.x - game->fps.pos.x + (1 - game->ray.dda.step.x) / 2) / game->ray.ray_vec.x;
	else if (game->ray.dda.side == 1)
		game->ray.dda.wall_dist = (game->ray.dda.map.y - game->fps.pos.y + (1 - game->ray.dda.step.y) / 2) / game->ray.ray_vec.y;
	game->ray.dda.line_height = (int)(WIN_HEIGHT / game->ray.dda.wall_dist);
}

void	ray_vector_dir(t_game *game)
{
	game->ray.ray_vec.x = game->fps.dir.x + game->fps.plane.x * game->ray.mnchi;
	game->ray.ray_vec.y = game->fps.dir.y + game->fps.plane.y * game->ray.mnchi;
	game->fps.plane.x = -game->fps.dir.y * 0.66;
	game->fps.plane.y = game->fps.dir.x * 0.66;
	// printf("*****************************************************\n");
	// printf("ray->camera %f\n", game->ray.mnchi);
	// printf("plane x: %f, plane y: %f\n", game->fps.plane.x, game->fps.plane.y);
	// printf("dir x: %f, dir y: %f\n", game->fps.dir.x, game->fps.dir.y);
	// printf("ray vec x: %f, ray vec y: %f\n", game->ray.ray_vec.x, game->ray.ray_vec.y);
	// printf("*****************************************************\n\n");
}

void	prepare_raycasting(t_game *game, int i)
{
	game->ray.mnchi = 2 * i / (double)WIN_WIDTH - 1;
	ray_vector_dir(game);
	dda(game);
	calculate_line_height(game);
	calculate_draw_start_end(game);
	// printf("=====================================================\n");
	// printf("game.ray.dda.draw_start: %d\n", game->ray.dda.draw_start);
	// printf("game.ray.dda.draw_end: %d\n", game->ray.dda.draw_end);
	// printf("=====================================================\n");
}

// void	da_movement_thang(t_game *game)
// {
// 	if (game->key.w == 1)
// 	{
// 		if (game->parse.map->tab[(int)(game->fps.pos.y + game->fps.dir.y * 0.1)][(int)game->fps.pos.x] != '1')
// 			game->fps.pos.y += game->fps.dir.y * 0.1;
// 		if (game->parse.map->tab[(int)game->fps.pos.y][(int)(game->fps.pos.x + game->fps.dir.x * 0.1)] != '1')
// 			game->fps.pos.x += game->fps.dir.x * 0.1;
// 	}
// 	if (game->key.s == 1)
// 	{
// 		if (game->parse.map->tab[(int)(game->fps.pos.y - game->fps.dir.y * 0.1)][(int)game->fps.pos.x] != '1')
// 			game->fps.pos.y -= game->fps.dir.y * 0.1;
// 		if (game->parse.map->tab[(int)game->fps.pos.y][(int)(game->fps.pos.x - game->fps.dir.x * 0.1)] != '1')
// 			game->fps.pos.x -= game->fps.dir.x * 0.1;
// 	}
// 	if (game->key.a == 1)
// 	{
// 		if (game->parse.map->tab[(int)(game->fps.pos.y - game->fps.plane.y * 0.1)][(int)game->fps.pos.x] != '1')
// 			game->fps.pos.y -= game->fps.plane.y * 0.1;
// 		if (game->parse.map->tab[(int)game->fps.pos.y][(int)(game->fps.pos.x - game->fps.plane.x * 0.1)] != '1')
// 			game->fps.pos.x -= game->fps.plane.x * 0.1;
// 	}
// 	if (game->key.d == 1)
// 	{
// 		if (game->parse.map->tab[(int)(game->fps.pos.y + game->fps.plane.y * 0.1)][(int)game->fps.pos.x] != '1')
// 			game->fps.pos.y += game->fps.plane.y * 0.1;
// 		if (game->parse.map->tab[(int)game->fps.pos.y][(int)(game->fps.pos.x + game->fps.plane.x * 0.1)] != '1')
// 			game->fps.pos.x += game->fps.plane.x * 0.1;
// 	}
// }

int	kaboom(void *param)
{
	t_game	*game;
	int		i;

	game = (t_game *)param;
	i = 0;
	// da_movement_thang(game);
	while (i < WIN_WIDTH)
	{
		prepare_raycasting(game, i);
		draw_stripe(game, i);
		i++;
	}
	mlx_put_image_to_window(game->cmlx.ptr, game->cmlx.mlx_win,
		game->cmlx.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	parser(&game.parse, argc, argv);
	init_game(&game);
	mlx_hook(game.cmlx.mlx_win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.cmlx.mlx_win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.cmlx.mlx_win, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game.cmlx.ptr, kaboom, &game);
	mlx_loop(game.cmlx.ptr);
	return (0);
}
