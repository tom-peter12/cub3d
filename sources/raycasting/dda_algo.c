/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:01:03 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/25 15:06:32 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * 
 * @authors {tpetros, hatesfam}
 * 
 * @brief Calculate the draw start and end positions for rendering the wall.
 * 
 * This function is responsible for calculating the draw start and end positions 
 * for rendering the wall on the screen. It determines the vertical range of 
 * pixels that need to be drawn for the wall based on the line height and the 
 * window height.
 * 
 * The steps performed in this function are as follows:
 * 1. Calculate the draw start position by subtracting half of the line height 
 *    from half of the window height. If the calculated draw start position is 
 *    less than 0, set it to 0.
 * 
 * 2. Calculate the draw end position by adding half of the line height to half 
 *    of the window height. If the calculated draw end position is greater than 
 *    or equal to the window height, set it to the maximum window height - 1.
 * 
 * @param game Pointer to the game structure.
 * 
 * @return void
 */

void	calculate_draw_start_end(t_game *game)
{
	game->ray.dda.draw_start = -game->ray.dda.line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray.dda.draw_start < 0)
		game->ray.dda.draw_start = 0;
	game->ray.dda.draw_end = game->ray.dda.line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray.dda.draw_end >= WIN_HEIGHT)
		game->ray.dda.draw_end = WIN_HEIGHT - 1;
}

/**
 * 
 * @authors {tpetros, hatesfam}
 * 
 * @brief Calculate the line height for the DDA algorithm.
 * 
 * This function is responsible for calculating the line height for the Digital 
 * Differential Analyzer (DDA) algorithm. It determines the height of the wall 
 * that needs to be rendered on the screen based on the distance to the wall.
 * 
 * The steps performed in this function are as follows:
 * 1. Check the side of the wall that the ray hits. If it is side 0 (vertical 
 *    wall), calculate the wall distance based on the side distance and the 
 *    delta distance in the x direction.
 * 
 * 2. If it is side 1 (horizontal wall), calculate the wall distance based on 
 *    the side distance and the delta distance in the y direction.
 * 
 * 3. Calculate the line height by dividing the window height by the wall 
 *    distance.
 * 
 * @param game Pointer to the game structure.
 * 
 * @return void
 */

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

/**
 * 
 * @authors {tpetros, hatesfam}
 * 
 * @brief Calculate the side distances for the DDA algorithm.
 * 
 * This function is responsible for calculating the side distances for the 
 * Digital Differential Analyzer (DDA) algorithm. It determines the distance 
 * to the next side (either x or y) of the wall that the ray hits.
 * 
 * The steps performed in this function are as follows:
 * 1. Check the direction of the ray's x component. If it is negative, set the 
 *    step.x value to -1 and calculate the side distance based on the player's 
 *    position and the map coordinates.
 * 
 * 2. If the ray's x component is positive, set the step.x value to 1 and 
 *    calculate the side distance based on the map coordinates, the player's 
 *    position, and the delta distance.
 * 
 * 3. Check the direction of the ray's y component. If it is negative, set the 
 *    step.y value to -1 and calculate the side distance based on the player's 
 *    position and the map coordinates.
 * 
 * 4. If the ray's y component is positive, set the step.y value to 1 and 
 *    calculate the side distance based on the map coordinates, the player's 
 *    position, and the delta distance.
 * 
 * @param game Pointer to the game structure.
 * 
 * @return {void}
 * 
 */

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

/**
 * @authors {tpetros, hatesfam}
 * 
 * @brief Perform pre-DDA calculations.
 * 
 * This function is responsible for performing pre-DDA calculations, such as
 * setting the map coordinates and calculating the delta distances. It is 
 * called before entering the (Digital Differential Analyzer) algorithm loop.
 * 
 * The steps performed in this function are as follows:
 * 1. Set the map coordinates (game->ray.dda.map.x and game->ray.dda.map.y)
 * 	  to the integer values of the player's position.
 * 
 * 2. Calculate the delta distances (game->ray.dda.delta_dist.x and 
 *    game->ray.dda.delta_dist.y) based on the ray's direction.
 * 
 * 3. If the ray's direction component is not zero, the delta distance is
 *    calculated as the absolute value of 1 divided by the ray's direction 
 *    component. Otherwise, a large value (1e30) is used to represent infinity.
 * 
 * 4. Set the (game->ray.dda.hit) to 0, indicating that no wall has been hit.
 * 
 * 5. Call the calc_side_dist() function to calculate the side distances.
 * 
 * 
 * delta_dist.x: The distance you need to move in the X direction to reach 
 *               the next intersection.
 * 
 * delta_dist.y: The distance you need to move in the Y direction to reach 
 *               the next intersection.
 * 
 * @param game Pointer to the game structure.
 * 
 * @return {void}
 */

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

/**
 * @authors {tpetros, hatesfam}
 * 
 * @param {game} - Pointer to struct game
 * 
 * @brief
 * 
 * This is the entry point for the digital differential analyzer algorithm.
 * The DDA (Digital Differential Analyzer) algorithm is a line rasterization 
 * algorithm commonly used in computer graphics.
 * 
 * 1. The pre_dda() function is called to perform pre-DDA calculations, such as 
 *    setting the map coordinates and calculating the delta distances.
 * 
 * 2. The dda() function enters a loop that continues until a hit is detected. 
 *    The hit variable (game->ray.dda.hit) is initially set to 0.
 * 
 * 3. If the horizontal side distance is smaller, the algorithm updates the side
 *    distance (game->ray.dda.side_dst.x), increments the map coordinate
 *    (game->ray.dda.map.x), and sets the (game->ray.dda.side) to 0.
 * 
 * 4. If the vertical side distance is smaller, the algorithm updates the side 
 *    distance (game->ray.dda.side_dst.y), increments the map coordinate 
 *    (game->ray.dda.map.y), and sets the  (game->ray.dda.side) to 1.
 * 
 * 5. After updating the side distance and map coordinate, the algorithm checks
 *    if the current map cell contains a wall (indicated by '1' in the map data).
 *    If a wall is found, the hit variable is set to 1, indicating that the ray
 *    has hit a wall and the loop should exit.
 * 
 * @return {void}
*/

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
