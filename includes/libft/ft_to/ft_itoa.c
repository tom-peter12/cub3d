/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:29:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/30 21:15:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_numlen(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (++count);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	ft_check(int n)
{
	if (n < 0)
		return (ft_numlen(n) + 1);
	else
		return (ft_numlen(n));
}

char	*ft_itoa(int nb)
{
	int		count;
	char	*numeric;
	int		len;
	long	n;

	n = nb;
	len = ft_check(n);
	count = len;
	numeric = (char *)malloc(sizeof(char) * len + 1);
	if (!numeric)
		return (0);
	if (n < 0)
	{
		numeric[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		numeric[0] = '0';
	while (n > 0)
	{
		numeric[--count] = (n % 10) + '0';
		n = n / 10;
	}
	numeric[len] = '\0';
	return (numeric);
}
