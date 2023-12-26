/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:12:41 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/15 15:58:03 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Calculates the direction of the ray vector based on the player's 
 * 		  direction and camera position.
 * 
 * The ray vector is calculated using the following formula:
 * 
 * rayDir = dir + plane * camera
 * 
 * @param game A pointer to the game structure.
 * 
 * @return void
 */

void	ray_vector_dir(t_game *game)
{
	game->ray.ray_vec.x = game->fps.dir.x + game->fps.plane.x \
		* game->ray.camerax;
	game->ray.ray_vec.y = game->fps.dir.y + game->fps.plane.y \
		* game->ray.camerax;
}

/**
 * @brief Performs raycasting for a specific column of the screen.
 * 
 * This function calculates the camera position, direction of the ray vector,
 * performs the DDA algorithm, and calculates the line height and draw start/end
 * positions for the column.
 * 
 * @param game 	A pointer to the game structure.
 * @param i 	The column index.
 * 
 * @return { void }
 */

void	raycast(t_game *game, int i)
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
		raycast(game, i);
		render(game, i);
		i++;
	}
	minimap2d(game);
	mlx_put_image_to_window(game->cmlx.ptr, game->cmlx.mlx_win,
		game->cmlx.img, 0, 0);
	return (0);
}
