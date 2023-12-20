/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/20 15:09:13 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	follow_mouse(int x, int y, t_game *game)
{
	if (game->mouse.x > x && !game->key.left && !game->key.right)
	{
		game->fps.dir.x = game->fps.dir.x * cos(-ROT_WEIGHT)
			- game->fps.dir.y * sin(-ROT_WEIGHT);
		game->fps.dir.y = game->fps.old_dir_x * sin(-ROT_WEIGHT)
			+ game->fps.dir.y * cos(-ROT_WEIGHT);
		game->fps.plane.x = game->fps.plane.x * cos(-ROT_WEIGHT)
			- game->fps.plane.y * sin(-ROT_WEIGHT);
		game->fps.plane.y = game->fps.old_plane_x * sin(-ROT_WEIGHT)
			+ game->fps.plane.y * cos(-ROT_WEIGHT);
	}
	else if (game->mouse.x < x && !game->key.left && !game->key.right)
	{
		game->fps.dir.x = game->fps.dir.x * cos(ROT_WEIGHT)
			- game->fps.dir.y * sin(ROT_WEIGHT);
		game->fps.dir.y = game->fps.old_dir_x * sin(ROT_WEIGHT)
			+ game->fps.dir.y * cos(ROT_WEIGHT);
		game->fps.plane.x = game->fps.plane.x * cos(ROT_WEIGHT)
			- game->fps.plane.y * sin(ROT_WEIGHT);
		game->fps.plane.y = game->fps.old_plane_x * sin(ROT_WEIGHT)
			+ game->fps.plane.y * cos(ROT_WEIGHT);
	}
	game->mouse.x = x;
	game->mouse.y = y;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	parser(&game.parse, argc, argv);
	init_game(&game);
	mlx_hook(game.cmlx.mlx_win, 6, 1L << 6, follow_mouse, &game);
	mlx_hook(game.cmlx.mlx_win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.cmlx.mlx_win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.cmlx.mlx_win, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game.cmlx.ptr, kaboom, &game);
	mlx_loop(game.cmlx.ptr);
	return (0);
}
