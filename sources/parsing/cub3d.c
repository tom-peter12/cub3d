/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/27 21:00:59 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	ft_init_win(t_data *data)
// {
// 	data->cmlx->ptr = mlx_init();
// 	data->cmlx->mlx_win = mlx_new_window(data->cmlx->ptr, WIN_WIDTH, WIN_HEIGHT,
// 			"Wolfe... Nah cub3D");
// 	mlx_loop(data->cmlx);
// }

int	main(int argc, char **argv)
{
	t_parse	parse;
	// t_game	game;

	parser(&parse, argc, argv);
	// game.map = parse.holder;
	// ft_init_win(&data);
	return (0);
}
