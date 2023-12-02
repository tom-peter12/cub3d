/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/01 21:25:22 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_exit(t_game *game)
{
	if (game->cmlx.ptr || game->cmlx.img)
		mlx_destroy_image(game->cmlx.ptr, game->cmlx.img);
	if (game->cmlx.ptr || game->cmlx.mlx_win)
		mlx_destroy_window(game->cmlx.ptr, game->cmlx.mlx_win);
	exit_return_freer(&game->parse);
	return (0);
}

void	draw_player(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			game->cmlx.addr[(int)game->player.posx + i + ((int)game->player.posy + j) * WIN_WIDTH] = 0x00FF00;
			j++;
		}
		i++;
	}
}

void	mlx_clear_img(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = WIN_HEIGHT * WIN_WIDTH;
	while (i < j)
	{
		game->cmlx.addr[i] = 0x000000;
		i++;
	}
}

void	render(t_game *game)
{
	draw_player(game);
	mlx_put_image_to_window(game->cmlx.ptr, game->cmlx.mlx_win, \
		game->cmlx.img, 0, 0);
	mlx_loop(game->cmlx.ptr);
}

int	ft_key_events(int k_code, t_game *game)
{
	mlx_clear_window(game->cmlx.ptr, game->cmlx.mlx_win);
	mlx_clear_img(game);
	if (k_code == ESC)
		ft_exit(game);
	else if ((k_code == W) && game->player.posy > 0)
		game->player.posy = game->player.posy - 5;
	else if ((k_code == S) && game->player.posy < WIN_HEIGHT)
		game->player.posy = game->player.posy + 5;
	else if ((k_code == A) && game->player.posx > 0)
		game->player.posx = game->player.posx - 5;
	else if ((k_code == D) && game->player.posx < WIN_WIDTH)
		game->player.posx = game->player.posx + 5;
	render(game);
	return (0);
}

int	init_mlx(t_game *game)
{
	game->cmlx.ptr = mlx_init();
	game->cmlx.img = mlx_new_image(game->cmlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	game->cmlx.mlx_win = mlx_new_window(game->cmlx.ptr, WIN_WIDTH, WIN_HEIGHT,
			"Wolfe... Nah cub3D");
	game->cmlx.addr = (int *)mlx_get_data_addr(game->cmlx.img, &(game->cmlx.bpp),
			&(game->cmlx.line_length), &(game->cmlx.endian));
	mlx_hook(game->cmlx.mlx_win, 2, 1L << 0, ft_key_events, game);
	mlx_hook(game->cmlx.mlx_win, 17, 1L << 17, ft_exit, game);
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
				game->player.posx = j * (WIN_WIDTH / game->parse.map->width);
				game->player.posy = i * (WIN_HEIGHT / game->parse.map->height);
				if (game->parse.map->tab[i][j] == 'N')
					game->player.angle = PI / 2;
				else if (game->parse.map->tab[i][j] == 'S')
					game->player.angle = 3 * PI / 2;
				else if (game->parse.map->tab[i][j] == 'E')
					game->player.angle = 0;
				else if (game->parse.map->tab[i][j] == 'W')
					game->player.angle = PI;
			}
			j++;
		}
		i++;
	}
}

int	init_keys(t_game *game)
{
	game->key.a = 0;
	game->key.s = 0;
	game->key.d = 0;
	game->key.w = 0;
	game->key.left = 0;
	game->key.right = 0;
	game->key.down = 0;
	game->key.up = 0;
	return (0);
}

int	init_player(t_game *game)
{
	ft_locate_player(game);
	game->player.delta_x = 0;
	game->player.delta_y = 0;
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

int	main(int argc, char **argv)
{
	t_game	game;

	parser(&game.parse, argc, argv);
	init_game(&game);
	render(&game);
	return (0);
}
