/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:30:57 by tpetros           #+#    #+#             */
/*   Updated: 2022/05/31 18:31:00 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_valid(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	int	i;

	if (ft_check_valid(base) == 1)
	{
		if (nb == -2147483648)
		{
			ft_putnbr_base((nb / ft_strlen(base)), base);
			write(1, &"8", 1);
		}
		else if (nb < 0)
		{
			write(1, &"-", 1);
			ft_putnbr_base((nb * -1), base);
		}
		else if (nb > ft_strlen(base))
		{
			ft_putnbr_base((nb / ft_strlen(base)), base);
			ft_putnbr_base((nb % ft_strlen(base)), base);
		}
		else
		{
			i = base[nb % ft_strlen(base)];
			write(1, &i, 1);
		}
	}
}
