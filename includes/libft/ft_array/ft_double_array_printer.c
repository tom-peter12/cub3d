/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array_printer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:29:03 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/24 14:31:25 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_double_array_printer(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		ft_putstr_fd(arr[i], 1);
		i++;
	}
}
