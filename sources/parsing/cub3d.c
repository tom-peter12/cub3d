/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/24 00:15:44 by tpetros          ###   ########.fr       */
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

int	ft_is_dir(char *dir)
{
	if (open(dir, O_DIRECTORY) >= 0)
	{
		ft_putendl_fd("Error\nPlease provide a file", 2);
		return (1);
	}
	else
		return (0);
}

int	ft_validate_args(t_parse *parse, int argc, char **argv)
{
	char	**hold;

	if (argc != 2 || argv[1][0] == '\0')
		return (ft_putendl_fd("Error\nInvalid number of arguments", 2), 1);
	hold = ft_split(argv[1], ' ');
	if (ft_strcmp(hold[0] + ft_strlen(hold[0]) - 4, ".cub") != 0
	|| (ft_strcmp(hold[0], ".cub") == 0))
	{
		ft_putendl_fd("Error\nInvalid file extension", 2);
		return (1);
	}
	parse->map_file = ft_strdup(hold[0]);
	ft_double_array_free(hold);
	hold = NULL;
	return (0);
}

int	ft_parse_cub(t_parse *parse)
{
	// char	*tmp;
	
	parse->map_fd = open(parse->map_file, O_RDONLY);
	if (parse->map_fd == -1)
	{
		ft_putendl_fd("Error", 2);
		return (perror(""), 1);
	}
	if (ft_is_dir(parse->map_file))
		return (1);
	parse->line = get_next_line(parse->map_fd);
	printf("%s\n", parse->line);
	if (!parse->line)
		return (ft_putendl_fd("Error\nFile cannot be empty", 2), 1);
	// while (parse->line)
	// {
	// 	tmp = ft_substr(parse->line, 0, 1);
	// 	// if (ft_strcmp(tmp, "NO"))
	// 	// 	ft_parse_north();
	// 	// else if (ft_strcmp(tmp, "SO"))
	// 	// 	ft_parse_south();
	// 	// else if (ft_strcmp(tmp, "WE"))
	// 	// 	ft_parse_west();
	// 	// else if (ft_strcmp(tmp, "EA"))
	// 	// 	ft_parse_east();
	// 	parse->line = get_next_line(parse->map_fd);
	// 	free(tmp);
	// }
	
	return (0);
}


int	main(int argc, char **argv)
{
	t_data	*data;
	t_parse	*parse;
	
	parse = ft_calloc(1, sizeof(parse));
	if (ft_validate_args(parse, argc, argv))
		return (1);
	if (ft_parse_cub(parse))
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (ft_putendl_fd("Error\nMalloc failed", 2), 1);
	// ft_init_win(data);
	return (0);
}
