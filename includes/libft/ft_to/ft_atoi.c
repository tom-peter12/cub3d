/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:30:01 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/08 15:04:41 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	ft_set_sign(const char *str, int i, int *sign)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	number;
	int		c;

	sign = 1;
	i = 0;
	number = 0;
	c = 0;
	while (ft_isspace(str[i]))
		i++;
	i = i + ft_set_sign(str, i, &sign);
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (0);
	while (ft_isdigit(str[i]))
	{
		number = number * 10 + str[i] - '0';
		c++;
		i++;
	}
	if (sign * number > INT_MAX || sign * number < INT_MIN || c > 10)
		return (-1);
	return ((int )(number * sign));
}
