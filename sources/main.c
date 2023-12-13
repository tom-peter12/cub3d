/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/12 19:02:11 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

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
