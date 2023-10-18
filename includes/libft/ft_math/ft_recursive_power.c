/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:35:56 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/03 18:03:37 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_recursive_power(int nb, int power)
{
	int	multiplier;

	multiplier = nb;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else if (power == 1)
		return (nb);
	else
		return (multiplier * ft_recursive_power(nb, power - 1));
}
