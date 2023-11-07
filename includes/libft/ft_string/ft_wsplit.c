/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:34:30 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/07 11:57:17 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_strings(const char *str, char *wspace)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_strchr(wspace, str[i]))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !ft_strchr(wspace, str[i]))
			i++;
	}
	return (count);
}

static int	ft_strsize(const char *str, char *wspace)
{
	int	i;

	i = 0;
	while (str[i] && !ft_strchr(wspace, str[i]))
		i++;
	return (i);
}

static char	*ft_word(const char *str, char *wspace)
{
	int		size;
	int		i;
	char	*word;

	i = 0;
	size = ft_strsize(str, wspace);
	word = (char *) malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	while (i < size)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_wsplit(const char *str)
{
	char	**strings;
	int		i;
	char	*ws;

	if (!str)
		return (NULL);
	ws = " \t\n\r";
	i = 0;
	strings = (char **) malloc(sizeof(char *) * (count_strings(str, ws) + 1));
	if (!strings)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && ft_strchr(ws, *str))
			str++;
		if (*str != '\0')
		{
			strings[i] = ft_word(str, ws);
			i++;
		}
		while (*str && !ft_strchr(ws, *str))
			str++;
	}
	strings[i] = 0;
	return (strings);
}
