/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:12:56 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/03 18:03:54 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_iterative_power(int nb, int power)
{
	int	multiplier;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else if (power == 1)
		return (nb);
	multiplier = nb;
	while (power > 1)
	{
		nb = multiplier * nb;
		power--;
	}
	return (nb);
}
