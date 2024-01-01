/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:25:25 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/26 18:25:50 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	right_rotation(t_game *game)
{
	game->fps.dir.x = game->fps.dir.x * cos(ROT_WEIGHT)
		- game->fps.dir.y * sin(ROT_WEIGHT);
	game->fps.dir.y = game->fps.old_dir_x * sin(ROT_WEIGHT)
		+ game->fps.dir.y * cos(ROT_WEIGHT);
	game->fps.plane.x = game->fps.plane.x * cos(ROT_WEIGHT)
		- game->fps.plane.y * sin(ROT_WEIGHT);
	game->fps.plane.y = game->fps.old_plane_x * sin(ROT_WEIGHT)
		+ game->fps.plane.y * cos(ROT_WEIGHT);
	game->fps.angle = game->fps.angle + \
		-1 * (ROT_WEIGHT * 180 / M_PI);
}

void	left_rotation(t_game *game)
{
	game->fps.dir.x = game->fps.dir.x * cos(-ROT_WEIGHT)
		- game->fps.dir.y * sin(-ROT_WEIGHT);
	game->fps.dir.y = game->fps.old_dir_x * sin(-ROT_WEIGHT)
		+ game->fps.dir.y * cos(-ROT_WEIGHT);
	game->fps.plane.x = game->fps.plane.x * cos(-ROT_WEIGHT)
		- game->fps.plane.y * sin(-ROT_WEIGHT);
	game->fps.plane.y = game->fps.old_plane_x * sin(-ROT_WEIGHT)
		+ game->fps.plane.y * cos(-ROT_WEIGHT);
	game->fps.angle = game->fps.angle + \
		(ROT_WEIGHT * 180 / M_PI);
}
