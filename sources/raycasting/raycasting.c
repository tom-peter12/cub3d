/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:12:41 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/13 16:02:19 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_vector_dir(t_game *game)
{
	game->ray.ray_vec.x = game->fps.dir.x + game->fps.plane.x * game->ray.camerax;
	game->ray.ray_vec.y = game->fps.dir.y + game->fps.plane.y * game->ray.camerax;
}

void	raycasting(t_game *game, int i)
{
	game->ray.camerax = 2 * (double)i / WIN_WIDTH - 1;
	ray_vector_dir(game);
	dda(game);
	calculate_line_height(game);
	calculate_draw_start_end(game);
}

int	kaboom(void *param)
{
	t_game	*game;
	int		i;

	game = (t_game *)param;
	i = 0;
	da_movement_thang(game);
	while (i < WIN_WIDTH)
	{
		raycasting(game, i);
		draw_stripe(game, i);
		i++;
	}
	mlx_put_image_to_window(game->cmlx.ptr, game->cmlx.mlx_win,
		game->cmlx.img, 0, 0);
	return (0);
}
