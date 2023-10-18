/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:08:57 by tpetros           #+#    #+#             */
/*   Updated: 2022/05/28 21:09:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\0')
			break ;
		if (str[i] >= ' ' && str[i] != 127)
		{
			ft_putchar(str[i]);
		}
		else if (str[i] < 32 || str[i] == 127)
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[str[i] / 16]);
			ft_putchar("0123456789abcdef"[str[i] % 16]);
		}
		i++;
	}
}

/*int		main(void)
{
	char	*str;

	str = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
}*/
