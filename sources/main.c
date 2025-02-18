/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/01 16:26:42 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	parser(&game.parse, argc, argv);
	init_game(&game);
	mlx_hook(game.cmlx.mlx_win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.cmlx.mlx_win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.cmlx.mlx_win, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game.cmlx.ptr, kaboom, &game);
	mlx_loop(game.cmlx.ptr);
	return (0);
}
