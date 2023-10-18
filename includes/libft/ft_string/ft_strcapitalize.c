/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:18:28 by tpetros           #+#    #+#             */
/*   Updated: 2022/05/28 18:13:14 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		x;
	char	a;

	i = 0;
	x = 1;
	while (*(str + i) != '\0')
	{
		a = *(str + i);
		if (x == 1 && a >= 'a' && a <= 'z')
		{
			str[i] -= 32;
		}
		else if (x == 0 && a >= 'A' && a <= 'Z')
		{
			str[i] += 32;
		}
		if (a < '0' || (a > '9' && a < 'A')
			|| (a > 'Z' && a < 'a') || a > 122)
			x = 1;
		else
			x = 0;
		i++;
	}
	return (str);
}

/*int		main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quaRAnte-deux; cinquante+et+un";

	printf("%s\n", ft_strcapitalize(str));
}
*/