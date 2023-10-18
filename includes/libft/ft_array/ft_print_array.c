/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:32:41 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/03 18:33:50 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_array(int *array, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		ft_putnbr_fd(array[i], 1);
	ft_putendl_fd("", 1);
}
