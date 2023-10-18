/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:07:26 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/02 20:12:01 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	ft_btree_apply_suffix(root->left, applyf);
	ft_btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}
