/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:07:13 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/03 18:03:34 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 1)
		return (0);
	else
	{
		i = 1;
		while (i <= nb)
		{
			if (i * i == nb)
				return (i);
			else if (i >= 46341)
				return (0);
			i++;
		}
		return (0);
	}
}
