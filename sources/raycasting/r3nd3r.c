/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r3nd3r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:09:03 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/14 17:00:48 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_ceiling(t_game *game, int i, int *j)
{
	while (*j < game->ray.dda.draw_start)
	{
		game->cmlx.addr[*j * WIN_WIDTH + i] = clr_rgb(game->parse.map->c_ceil);
		(*j)++;
	}
}

static void	draw_floor(t_game *game, int i, int *j)
{
	while (*j < WIN_HEIGHT)
	{
		game->cmlx.addr[*j * WIN_WIDTH + i] = clr_rgb(game->parse.map->c_floor);
		(*j)++;
	}
}

void	draw_stripe(t_game *game, int i)
{
	int	j;

	j = 0;
	draw_ceiling(game, i, &j);
	while (j < game->ray.dda.draw_end)
	{
		if (game->ray.dda.side == 0)
		{
			if (game->ray.ray_vec.x < 0)
				game->cmlx.addr[j * WIN_WIDTH + i] = WHITE;
			else if (game->ray.ray_vec.x > 0)
				game->cmlx.addr[j * WIN_WIDTH + i] = BLUE;
		}
		else
		{
			if (game->ray.ray_vec.y < 0)
				game->cmlx.addr[j * WIN_WIDTH + i] = RED;
			else if (game->ray.ray_vec.y > 0)
				game->cmlx.addr[j * WIN_WIDTH + i] = BLACK;
		}
		j++;
	}
	draw_floor(game, i, &j);
}
