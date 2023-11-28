/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/28 19:52:25 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_exit(t_cmlx *mlx)
{
	if (mlx->ptr || mlx->img)
		mlx_destroy_image(mlx->ptr, mlx->img);
	if (mlx->ptr || mlx->mlx_win)
		mlx_destroy_window(mlx->ptr, mlx->mlx_win);
	exit(1);
}

int	ft_key_events(int k_code, t_cmlx *mlx)
{
	if (k_code == 53)
		ft_exit(mlx);
	return (0);
}

void	ft_init_win(t_game *game)
{
	t_cmlx	cube;

	cube = game->cmlx;
	cube.ptr = mlx_init();
	cube.img = mlx_new_image(cube.ptr, WIN_WIDTH, WIN_HEIGHT);
	cube.mlx_win = mlx_new_window(cube.ptr, WIN_WIDTH, WIN_HEIGHT,
			"Wolfe... Nah cub3D");
	cube.addr = (int *)mlx_get_data_addr(cube.img, &(cube.bpp),
			&(cube.line_length), &(cube.endian));
	mlx_put_image_to_window(cube.ptr, cube.mlx_win, cube.img, 0, 0);
	mlx_hook(cube.mlx_win, 17, 1L << 17, ft_exit, &cube);
	mlx_key_hook(cube.mlx_win, ft_key_events, &cube);
	mlx_loop(cube.ptr);
}

int	main(int argc, char **argv)
{
	t_game	game;

	parser(&game.parse, argc, argv);
	ft_init_win(&game);
	return (0);
}
