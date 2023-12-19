/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:16:05 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/19 19:13:54 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_btree_level_count(t_btree *root)
{
	int	left_height;
	int	right_height;

	left_height = 0;
	right_height = 0;
	if (!root)
		return (0);
	left_height = ft_btree_level_count(root->left);
	right_height = ft_btree_level_count(root->right);
	if (left_height > right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}
