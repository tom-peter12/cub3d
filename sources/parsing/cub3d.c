/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/28 01:06:35 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	ft_init_win(t_data *data)
{
	data->cmlx->ptr = mlx_init();
	data->cmlx->mlx_win = mlx_new_window(data->cmlx->ptr, WIN_WIDTH, WIN_HEIGHT,
		"Wolfe... Nah cub3D");
	mlx_loop(data->cmlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_parse	parse;
	
	if (ft_validate_args(&parse, argc, argv))
		return (1);
	if (ft_validate_cub(&parse))
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (ft_putendl_fd("Error\nMalloc failed", 2), 1);
	// ft_init_win(data);
	return (0);
}
