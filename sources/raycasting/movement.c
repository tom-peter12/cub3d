/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:59:19 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/12 20:53:05 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	front_back_movement(t_game *game)
{
	if (game->key.w == 1)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.y + game->fps.dir.y * 0.1)]
			[(int)game->fps.pos.x] != '1')
			game->fps.pos.y += game->fps.dir.y * 0.1;
		if (game->parse.map->tab[(int)game->fps.pos.y]
			[(int)(game->fps.pos.x + game->fps.dir.x * 0.1)] != '1')
			game->fps.pos.x += game->fps.dir.x * 0.1;
	}
	if (game->key.s == 1)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.y - game->fps.dir.y * 0.1)]
			[(int)game->fps.pos.x] != '1')
			game->fps.pos.y -= game->fps.dir.y * 0.1;
		if (game->parse.map->tab[(int)game->fps.pos.y]
			[(int)(game->fps.pos.x - game->fps.dir.x * 0.1)] != '1')
			game->fps.pos.x -= game->fps.dir.x * 0.1;
	}
}

void	left_right_movement(t_game *game)
{
	if (game->key.a == 1)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.y - game->fps.plane.y * 0.1)]
			[(int)game->fps.pos.x] != '1')
			game->fps.pos.y -= game->fps.plane.y * 0.1;
		if (game->parse.map->tab[(int)game->fps.pos.y]
			[(int)(game->fps.pos.x - game->fps.plane.x * 0.1)] != '1')
			game->fps.pos.x -= game->fps.plane.x * 0.1;
	}
	if (game->key.d == 1)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.y + game->fps.plane.y * 0.1)]
			[(int)game->fps.pos.x] != '1')
			game->fps.pos.y += game->fps.plane.y * 0.1;
		if (game->parse.map->tab[(int)game->fps.pos.y]
			[(int)(game->fps.pos.x + game->fps.plane.x * 0.1)] != '1')
			game->fps.pos.x += game->fps.plane.x * 0.1;
	}
}

void rotation_movement(t_game *game)
{
	t_vector	old_dir;
	t_vector	old_plane;
	
	old_plane.x = game->fps.plane.x;
	old_dir.x = game->fps.dir.x;
	if (game->key.left == 1)
	{
		
		game->fps.dir.x = game->fps.dir.x * cos(-ROT_SPEED)
			- game->fps.dir.y * sin(-ROT_SPEED);
		game->fps.dir.y = old_dir.x * sin(-ROT_SPEED)
			+ game->fps.dir.y * cos(-ROT_SPEED);
		game->fps.plane.x = game->fps.plane.x * cos(-ROT_SPEED)
			- game->fps.plane.y * sin(-ROT_SPEED);
		game->fps.plane.y = old_plane.x * sin(-ROT_SPEED)
			+ game->fps.plane.y * cos(-ROT_SPEED);
	}
	if (game->key.right == 1)
	{
		game->fps.dir.x = game->fps.dir.x * cos(ROT_SPEED)
			- game->fps.dir.y * sin(ROT_SPEED);
		game->fps.dir.y = old_dir.x * sin(ROT_SPEED) 
			+ game->fps.dir.y * cos(ROT_SPEED);
		game->fps.plane.x = game->fps.plane.x * cos(ROT_SPEED)
			- game->fps.plane.y * sin(ROT_SPEED);
		game->fps.plane.y = old_plane.x * sin(ROT_SPEED)
			+ game->fps.plane.y * cos(ROT_SPEED);
	}
}

void	da_movement_thang(t_game *game)
{
	front_back_movement(game);
	left_right_movement(game);
	rotation_movement(game);
}

