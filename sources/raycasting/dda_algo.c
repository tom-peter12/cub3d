/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:01:03 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/18 19:22:48 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_draw_start_end(t_game *game)
{
	game->ray.dda.draw_start = -game->ray.dda.line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray.dda.draw_start < 0)
		game->ray.dda.draw_start = 0;
	game->ray.dda.draw_end = game->ray.dda.line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray.dda.draw_end >= WIN_HEIGHT)
		game->ray.dda.draw_end = WIN_HEIGHT - 1;
}

void	calculate_line_height(t_game *game)
{
	if (game->ray.dda.side == 0)
		game->ray.dda.wall_dist = (game->ray.dda.side_dst.x
				- game->ray.dda.delta_dist.x);
	else if (game->ray.dda.side == 1)
		game->ray.dda.wall_dist = (game->ray.dda.side_dst.y
				- game->ray.dda.delta_dist.y);
	game->ray.dda.line_height = (int)(WIN_HEIGHT / game->ray.dda.wall_dist);
}

void	calc_side_dist(t_game *game)
{
	if (game->ray.ray_vec.x < 0)
	{
		game->ray.dda.step.x = -1;
		game->ray.dda.side_dst.x = (game->fps.pos.x - game->ray.dda.map.x)
			* game->ray.dda.delta_dist.x;
	}
	else
	{
		game->ray.dda.step.x = 1;
		game->ray.dda.side_dst.x = (game->ray.dda.map.x + 1.0 - game->fps.pos.x)
			* game->ray.dda.delta_dist.x;
	}
	if (game->ray.ray_vec.y < 0)
	{
		game->ray.dda.step.y = -1;
		game->ray.dda.side_dst.y = (game->fps.pos.y - game->ray.dda.map.y)
			* game->ray.dda.delta_dist.y;
	}
	else
	{
		game->ray.dda.step.y = 1;
		game->ray.dda.side_dst.y = (game->ray.dda.map.y + 1.0 - game->fps.pos.y)
			* game->ray.dda.delta_dist.y;
	}
}

void	pre_dda(t_game *game)
{
	game->ray.dda.map.x = (int)game->fps.pos.x;
	game->ray.dda.map.y = (int)game->fps.pos.y;
	game->ray.dda.delta_dist.x = 1e30;
	if (game->ray.ray_vec.x != 0)
		game->ray.dda.delta_dist.x = fabs(1.0 / game->ray.ray_vec.x);
	game->ray.dda.delta_dist.y = 1e30;
	if (game->ray.ray_vec.y != 0)
		game->ray.dda.delta_dist.y = fabs(1.0 / game->ray.ray_vec.y);
	game->ray.dda.hit = 0;
	calc_side_dist(game);
}

void	dda(t_game *game)
{
	pre_dda(game);
	while (game->ray.dda.hit == 0)
	{
		if (game->ray.dda.side_dst.x < game->ray.dda.side_dst.y)
		{
			game->ray.dda.side_dst.x += game->ray.dda.delta_dist.x;
			game->ray.dda.map.x += game->ray.dda.step.x;
			game->ray.dda.side = 0;
		}
		else
		{
			game->ray.dda.side_dst.y += game->ray.dda.delta_dist.y;
			game->ray.dda.map.y += game->ray.dda.step.y;
			game->ray.dda.side = 1;
		}
		if (game->parse.map->tab[(int)game->ray.dda.map.x] \
			[(int)game->ray.dda.map.y] == '1')
			game->ray.dda.hit = 1;
	}
}
