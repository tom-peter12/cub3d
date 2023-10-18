/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:25:01 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/03 18:04:00 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_iterative_factorial(int nb)
{
	int	fact;

	if (nb < 0)
	{
		return (0);
	}
	fact = 1;
	while (nb > 1)
	{
		fact = fact * (nb);
		nb--;
	}
	return (fact);
}
