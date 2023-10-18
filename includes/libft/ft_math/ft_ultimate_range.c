/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:01:53 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/03 18:03:24 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ptr;
	int	i;

	ptr = (int *)malloc(sizeof(int) * (max - min));
	if (min >= max)
		return (0);
	if (!ptr)
		return (-1);
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		i ++;
		min ++;
	}
	*range = ptr;
	return (i);
}
