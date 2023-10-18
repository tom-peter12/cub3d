/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/18 22:23:12 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void	ft_init_win(t_data *data)
{
	data->mlx->ptr = mlx_init();
	data->mlx->mlx_win = mlx_new_window(data->mlx->ptr, WIN_WIDTH, WIN_HEIGHT,
		"Wolfe... Nah cub3D");
	// data->mlx->img = mlx_new_image(data->mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	// data->mlx->addr = (int *)mlx_get_data_addr(data->mlx->img, 
	// &(data->mlx->bpp), &(data->mlx->line_length), &(data->mlx->endian));
	mlx_loop(data->mlx);
}

int	ft_is_dir(char *dir)
{
	if (open(dir, __O_DIRECTORY) >= 0)
	{
		ft_putendl_fd("Error\nPlease provide a file", 2);
		return (1);
	}
	else
		return (0);
}

int	ft_validate_args(char **argv)
{
	char	**hold;

	hold = ft_split(argv[1], ' ');
	if (ft_strcmp(hold[0] + ft_strlen(hold[0]) - 4, ".cub") != 0
	|| (ft_strcmp(hold[0], ".cub") == 0))
	{
		ft_putendl_fd("Error\nInvalid file extension", 2);
		return (1);
	}
	if (open(hold[0], O_RDONLY) == -1)
	{
		ft_putendl_fd("Error", 2);
		perror("");
		return (1);
	}
	if (ft_is_dir(hold[0]))
		return (1);
	ft_double_array_free(hold);
	hold = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc != 2)
	{
		ft_putendl_fd("Error\nInvalid number of arguments", 2);
		return (1);
	}
	if (ft_validate_args(argv))
		return (1);
	ft_init_win(&data);
	return (0);
}
