/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/31 22:34:38 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	follow_mouse(int x, int y, t_game *game)
{
	if (x < 0 || x > WIN_WIDTH || y > WIN_HEIGHT || y < 0)
		return (0);
	if (game->mouse.x > x && !game->key.left && !game->key.right)
		left_rotation(game);
	else if (game->mouse.x < x && !game->key.left && !game->key.right)
		right_rotation(game);
	game->mouse.x = x;
	game->mouse.y = y;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	parser(&game.parse, argc, argv);
	printf("parse done\n");
	init_game(&game);
	mlx_hook(game.cmlx.mlx_win, 6, 1L << 6, follow_mouse, &game);
	mlx_hook(game.cmlx.mlx_win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.cmlx.mlx_win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.cmlx.mlx_win, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game.cmlx.ptr, kaboom, &game);
	mlx_loop(game.cmlx.ptr);
	return (0);
}
