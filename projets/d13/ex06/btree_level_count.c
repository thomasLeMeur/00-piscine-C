/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 11:31:34 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/18 11:31:36 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

#define MAX(x, y) (((x) < (y)) ? (y) : (x))

int	btree_level_count(t_btree *root)
{
	int	nb;

	if (!root)
		return (0);
	nb = MAX(btree_level_count(root->left), btree_level_count(root->right));
	return (1 + nb);
}
