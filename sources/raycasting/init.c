/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:16:56 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/12 19:36:10 by tpetros          ###   ########.fr       */
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
	game->cmlx.addr = (int *)mlx_get_data_addr(game->cmlx.img,
			&(game->cmlx.bpp), &(game->cmlx.line_length), &(game->cmlx.endian));
	return (0);
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

int	init_game(t_game *game)
{
	if (init_mlx(game))
		return (1);
	if (init_keys(game))
		return (1);
	ft_locate_player(game);
	printf("************************\n");
	printf("Player's location: [%f, %f]\n", game->fps.pos.x, game->fps.pos.y);
	printf("************************\n");
	return (0);
}
