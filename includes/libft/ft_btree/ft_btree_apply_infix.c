/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:06:11 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/02 22:20:03 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*   4
    / \
   2   6
  / \ / \
 1  3 5  7
*/

//  1 2 3 4 5 6 7

void ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
    if (!root || applyf == NULL)
		return ;
	ft_btree_apply_infix(root->left, applyf);
	applyf(root->item);
	ft_btree_apply_infix(root->right, applyf);
}
