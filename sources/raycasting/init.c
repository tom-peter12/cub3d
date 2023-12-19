/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:16:56 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/19 19:06:56 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * 
 * The mlx_init function creates a connection between the software and the 
 * x-server. This enables the software to interact with the server, such that
 * it can request the server specific tasks such as, to draw specific things
 * on this part of the display, or check if a user interupts the program using
 * any input, keyboard or mouse events.
 * 
 * If the mlx_init function fails it returns NULL if not it returns a pointer
 * to the connection. As the man page for mlx conforms this pointer is a 
 * "connection identifier".
 * 
 * The above description is only applicable to linux because in macos, mlx uses
 * opengl not x-server. But I would be surprised if they don't work similary.
 *  
 * 
 * @authors tpetros, hatesfam
 * 
 * @brief
 * As the name suggests this function initializes the mlx for display.
 * 1. Initialize the connection with the x-server.
 * 2. Initialize the images which the pixels will be drawn into.
 * 3. Initialize the window, with proper height, width and legend
 * 4. Initialize the address of each pixels which the image will be stored.
 *  
 * @param {game} - Pointer to the game data struct.
 * Takes the pointer to the whole data stored of the game, 
 * 
 * suggestion: could have passed only the pointer to mlx, but since its pass
 * by reference we don't have any overhead or optimization problem. And also
 * the mlx variables are defined as a substruct to the game struct.
 * 
 *
*/

int	init_mlx(t_game *game)
{
	game->cmlx.ptr = mlx_init();
	if (!game->cmlx.ptr)
		return (1);
	game->cmlx.img = mlx_new_image(game->cmlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!game->cmlx.img)
		return (1);
	game->cmlx.mlx_win = mlx_new_window(game->cmlx.ptr, WIN_WIDTH, WIN_HEIGHT,
			"Wolfe... Nah cub3D");
	if (!game->cmlx.mlx_win)
		return (1);
	game->cmlx.addr = (int *)mlx_get_data_addr(game->cmlx.img,
			&(game->cmlx.bpp), &(game->cmlx.line_length), &(game->cmlx.endian));
	if (!game->cmlx.addr)
		return (1);
	return (0);
}

/**
 * 
 * @authors tpetros, hatesfam
 *
 * 
 * @brief
 * As the name suggests, we set the key corresponding values to 0. This will
 * ensure that our game starts without any key pressed. If this step is not 
 * done, the game will act weirdly, start with the fps moving and eventually
 * seg faulting.
 * 
 * 
 * @return {void}
 * 
*/

void	init_keys(t_game *game)
{
	game->key.a = 0;
	game->key.s = 0;
	game->key.d = 0;
	game->key.w = 0;
	game->key.left = 0;
	game->key.right = 0;
	game->key.down = 0;
	game->key.up = 0;
}

/**
 * Initializes the textures for the game.
 * 
 * @brief
 * This function loads the textures from the provided file paths using 
 * mlx_xpm_file_to_image function.
 * It iterates through the four textures and assigns the loaded image,
 * width, and height to the corresponding
 * texture struct in the game data. If the image loading fails for any 
 * texture, it calls the close_window function to handle the error.
 * 
 * The mlx_xpm_file_to_image reads an xpm image file and creates an
 * image in memory. If it fails, it will return a NULL pointer otherwise
 *  it will return a non-null pointer that identifies the image. 
 * 
 * @param {game} - Pointer to the game data struct.
 * 
 * @return {void}
 */

void	init_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->texture[i].img = mlx_xpm_file_to_image(game->cmlx.ptr, \
			game->parse.textures[i], &game->texture[i].width, \
			&game->texture[i].height);
		if (game->texture[i].img == NULL)
			close_window(game);
		i++;
	}
}

int	init_game(t_game *game)
{
	if (init_mlx(game))
		return (1);
	init_keys(game);
	ft_locate_player(game);
	init_textures(game);
	return (0);
}
