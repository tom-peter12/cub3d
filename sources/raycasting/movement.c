/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:59:19 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/13 20:17:34 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	front_back_movement(t_game *game)
{
	if (game->key.w == 1)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.x + game->fps.dir.x
				* MOVE_SPEED)][(int)game->fps.pos.y] != '1')
			game->fps.pos.x += game->fps.dir.x * MOVE_SPEED;
		if (game->parse.map->tab[(int)game->fps.pos.x]
			[(int)(game->fps.pos.y + game->fps.dir.y * MOVE_SPEED)] != '1')
			game->fps.pos.y += game->fps.dir.y * MOVE_SPEED;
	}
	if (game->key.s == 1)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.x - game->fps.dir.x
				* MOVE_SPEED)][(int)game->fps.pos.y] != '1')
			game->fps.pos.x -= game->fps.dir.x * MOVE_SPEED;
		if (game->parse.map->tab[(int)game->fps.pos.x]
			[(int)(game->fps.pos.y - game->fps.dir.y * MOVE_SPEED)] != '1')
			game->fps.pos.y -= game->fps.dir.y * MOVE_SPEED;
	}
}

void	left_right_movement(t_game *game)
{
	if (game->key.a == 1)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.x - game->fps.plane.x
				* MOVE_SPEED)][(int)game->fps.pos.y] != '1')
			game->fps.pos.x -= game->fps.plane.x * MOVE_SPEED;
		if (game->parse.map->tab[(int)game->fps.pos.x]
			[(int)(game->fps.pos.y - game->fps.plane.y * MOVE_SPEED)] != '1')
			game->fps.pos.y -= game->fps.plane.y * MOVE_SPEED;
	}
	if (game->key.d == 1)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.x + game->fps.plane.x
				* MOVE_SPEED)][(int)game->fps.pos.y] != '1')
			game->fps.pos.x += game->fps.plane.x * MOVE_SPEED;
		if (game->parse.map->tab[(int)game->fps.pos.x]
			[(int)(game->fps.pos.y + game->fps.plane.y * MOVE_SPEED)] != '1')
			game->fps.pos.y += game->fps.plane.y * MOVE_SPEED;
	}
}

void	rotation_movement(t_game *game)
{
	game->fps.old_dir = game->fps.dir.x;
	game->fps.old_plane = game->fps.plane.x;
	if (game->key.left == 1)
	{
		game->fps.dir.x = game->fps.dir.x * cos(-ROT_SPEED)
			- game->fps.dir.y * sin(-ROT_SPEED);
		game->fps.dir.y = game->fps.old_dir * sin(-ROT_SPEED)
			+ game->fps.dir.y * cos(-ROT_SPEED);
		game->fps.plane.x = game->fps.plane.x * cos(-ROT_SPEED)
			- game->fps.plane.y * sin(-ROT_SPEED);
		game->fps.plane.y = game->fps.old_plane * sin(-ROT_SPEED)
			+ game->fps.plane.y * cos(-ROT_SPEED);
	}
	if (game->key.right == 1)
	{
		game->fps.dir.x = game->fps.dir.x * cos(ROT_SPEED)
			- game->fps.dir.y * sin(ROT_SPEED);
		game->fps.dir.y = game->fps.old_dir * sin(ROT_SPEED)
			+ game->fps.dir.y * cos(ROT_SPEED);
		game->fps.plane.x = game->fps.plane.x * cos(ROT_SPEED)
			- game->fps.plane.y * sin(ROT_SPEED);
		game->fps.plane.y = game->fps.old_plane * sin(ROT_SPEED)
			+ game->fps.plane.y * cos(ROT_SPEED);
	}
}

void	da_movement_thang(t_game *game)
{
	front_back_movement(game);
	left_right_movement(game);
	rotation_movement(game);
}
