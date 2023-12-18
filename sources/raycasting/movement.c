/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:59:19 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/18 20:18:13 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	front_back_movement(t_game *game)
{
	if (game->key.w)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.x + game->fps.dir.x \
				* MOVE_WEIGHT)][(int)game->fps.pos.y] != '1')
			game->fps.pos.x += game->fps.dir.x * MOVE_WEIGHT;
		if (game->parse.map->tab[(int)game->fps.pos.x] \
			[(int)(game->fps.pos.y + game->fps.dir.y * MOVE_WEIGHT)] != '1')
			game->fps.pos.y += game->fps.dir.y * MOVE_WEIGHT;
	}
	if (game->key.s)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.x - game->fps.dir.x \
				* MOVE_WEIGHT)][(int)game->fps.pos.y] != '1')
			game->fps.pos.x -= game->fps.dir.x * MOVE_WEIGHT;
		if (game->parse.map->tab[(int)game->fps.pos.x] \
			[(int)(game->fps.pos.y - game->fps.dir.y * MOVE_WEIGHT)] != '1')
			game->fps.pos.y -= game->fps.dir.y * MOVE_WEIGHT;
	}
}

void	left_right_movement(t_game *game)
{
	if (game->key.a)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.x - game->fps.plane.x \
				* MOVE_WEIGHT)][(int)game->fps.pos.y] != '1')
			game->fps.pos.x -= game->fps.plane.x * MOVE_WEIGHT;
		if (game->parse.map->tab[(int)game->fps.pos.x] \
			[(int)(game->fps.pos.y - game->fps.plane.y * MOVE_WEIGHT)] != '1')
			game->fps.pos.y -= game->fps.plane.y * MOVE_WEIGHT;
	}
	if (game->key.d)
	{
		if (game->parse.map->tab[(int)(game->fps.pos.x + game->fps.plane.x
				* MOVE_WEIGHT)][(int)game->fps.pos.y] != '1')
			game->fps.pos.x += game->fps.plane.x * MOVE_WEIGHT;
		if (game->parse.map->tab[(int)game->fps.pos.x]
			[(int)(game->fps.pos.y + game->fps.plane.y * MOVE_WEIGHT)] != '1')
			game->fps.pos.y += game->fps.plane.y * MOVE_WEIGHT;
	}
}

/**
 * Rotates the user using the LEFT and RIGHT key.
 *
 * @author {tpetros, hatesfam}
 * 
 * @param game The game struct containing the player's information.
 * 
 * @brief
 * 
 * To rotate the user, we multiply the current direction and plane vectors
 * using the "rotation matrix".
 * 
 * The rotation matrix
 *  --					--
 * | cos (θ)   -sin (θ)	  |
 * | sin (θ)   cos	(θ)   |
 *  --					--
 * 
 * This method rotates a given vector (θ) radian in the orthogonal system
 * counter clockwise.
 * 
 * NOTE: Since each dir components are computed separately (x, y), we need extra
 * 		 variables to store the old x componenet of both the plane and the
 * 		 direction vectors.
 * 
 * @return {void}
 * 
 */
void	rotation_movement(t_game *game)
{
	game->fps.old_dir_x = game->fps.dir.x;
	game->fps.old_plane_x = game->fps.plane.x;
	if (game->key.left && !game->key.right)
	{
		game->fps.dir.x = game->fps.dir.x * cos(-ROT_WEIGHT)
			- game->fps.dir.y * sin(-ROT_WEIGHT);
		game->fps.dir.y = game->fps.old_dir_x * sin(-ROT_WEIGHT)
			+ game->fps.dir.y * cos(-ROT_WEIGHT);
		game->fps.plane.x = game->fps.plane.x * cos(-ROT_WEIGHT)
			- game->fps.plane.y * sin(-ROT_WEIGHT);
		game->fps.plane.y = game->fps.old_plane_x * sin(-ROT_WEIGHT)
			+ game->fps.plane.y * cos(-ROT_WEIGHT);
	}
	if (!game->key.left && game->key.right)
	{
		game->fps.dir.x = game->fps.dir.x * cos(ROT_WEIGHT)
			- game->fps.dir.y * sin(ROT_WEIGHT);
		game->fps.dir.y = game->fps.old_dir_x * sin(ROT_WEIGHT)
			+ game->fps.dir.y * cos(ROT_WEIGHT);
		game->fps.plane.x = game->fps.plane.x * cos(ROT_WEIGHT)
			- game->fps.plane.y * sin(ROT_WEIGHT);
		game->fps.plane.y = game->fps.old_plane_x * sin(ROT_WEIGHT)
			+ game->fps.plane.y * cos(ROT_WEIGHT);
	}
}

void	da_movement_thang(t_game *game)
{
	front_back_movement(game);
	left_right_movement(game);
	rotation_movement(game);
}
