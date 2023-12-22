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

void	draw_square(t_game *game, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			game->cmlx.addr[(y + j) * WIN_WIDTH + (x + i)] = color;
			j++;
		}
		i++;
	}
}

void	minimap2d(t_game *game)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < (int)game->parse.map->height)
	{
		j = 0;
		while (j < (int)game->parse.map->width)
		{
			tmp = ft_strchr("NSEW", game->parse.map->tab[i][j]);
			if (game->parse.map->tab[i][j] == '0' || (tmp && tmp[0]))
				draw_square(game, j * MINIMAP_SCALE, i * MINIMAP_SCALE, 0);
			j++;
		}
		i++;
	}
	draw_square(game, (int)game->fps.pos.y * MINIMAP_SCALE, \
		(int)game->fps.pos.x * MINIMAP_SCALE, 0xFFFFFF);
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
