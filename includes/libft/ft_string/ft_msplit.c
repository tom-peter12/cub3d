/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:34:22 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/22 19:23:08 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_spacer(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (1);
		}
		++i;
	}
	return (0);
}

static int	count_words(char const *s, char *c)
{
	int	sum;
	int	in_word;

	sum = 0;
	in_word = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (!is_spacer(c, *s) && in_word == 0)
		{
			++sum;
			in_word = 1;
		}
		else if (is_spacer(c, *s))
			in_word = 0;
		s++;
	}
	return (sum);
}

static int	word_len(char const *s, char *c, int i)
{
	int	len;

	len = 0;
	while (!is_spacer(c, s[i]) && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**malloc_error(char **new, int j)
{
	while (j >= 0)
	{
		free(new[j]);
		--j;
	}
	free(new);
	return (NULL);
}

char	**ft_msplit(char *s, char *c)
{
	int		i;
	int		j;
	char	**new;

	new = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		while (is_spacer(c, s[i]))
			i++;
		new[j] = ft_substr(s, i, word_len(s, c, i));
		if (!new[j])
			return (malloc_error(new, j));
		i += word_len(s, c, i);
		++j;
	}
	new[j] = (NULL);
	return (new);
}
