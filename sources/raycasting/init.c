/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:16:56 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/14 17:01:08 by tpetros          ###   ########.fr       */
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

void	init_textures(t_game *game)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		game->texture[i].img = mlx_xpm_file_to_image(game->cmlx.ptr, \
			game->parse.textures[i], &game->texture[i].width, \
			&game->texture[i].width);
		if (game->texture[i].img == NULL)
			close_window(game);
		i++;
	}
}

int	init_game(t_game *game)
{
	if (init_mlx(game))
		return (1);
	if (init_keys(game))
		return (1);
	ft_locate_player(game);
	init_textures(game);
	return (0);
}
