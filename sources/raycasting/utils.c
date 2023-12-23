/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:34:53 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/23 15:52:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	if (keycode == ESC)
	{
		close_window(game);
		exit_return_freer(&game->parse, 0);
	}
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->key.w = 0;
	if (keycode == A)
		game->key.a = 0;
	if (keycode == S)
		game->key.s = 0;
	if (keycode == D)
		game->key.d = 0;
	if (keycode == LEFT)
		game->key.left = 0;
	if (keycode == RIGHT)
		game->key.right = 0;
	return (0);
}

int	clr_rgb(t_color *color)
{
	return (color->r << 16 | color->g << 8 | color->b);
}

int	close_window(t_game *game)
{
	if (game->cmlx.ptr || game->cmlx.mlx_win)
		mlx_destroy_window(game->cmlx.ptr, game->cmlx.mlx_win);
	if (game->cmlx.ptr || game->cmlx.img)
		mlx_destroy_image(game->cmlx.ptr, game->cmlx.img);
	exit_return_freer(&game->parse, 0);
	return (0);
}
