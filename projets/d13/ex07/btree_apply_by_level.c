/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 11:41:31 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/18 15:22:42 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_enqueue(t_floor **begin_list, t_btree *elem, int depth)
{
	t_floor	*i;
	t_floor	*new;

	i = *begin_list;
	new = (t_floor*)malloc(sizeof(t_floor));
	new->elem = elem;
	new->next = NULL;
	new->depth = depth;
	if (!i)
		return ((void)(*begin_list = new));
	while (i->next)
		i = i->next;
	i->next = new;
}

void	ft_dequeue(t_floor **begin_list)
{
	t_floor	*i;

	i = *begin_list;
	if (!i)
		return ;
	*begin_list = i->next;
	free(i);
	i = NULL;
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_floor	*list;
	t_btree	*tmp;

	if (!root)
		return ;
	list = NULL;
	ft_enqueue(&list, root, 0);
	while (list)
	{
		tmp = list->elem;
		if (tmp == root)
			(*applyf)(tmp->item, 0, 1);
		else
			(*applyf)(tmp->item, list->depth, 0);
		if (tmp->left)
			ft_enqueue(&list, tmp->left, list->depth + 1);
		if (tmp->right)
			ft_enqueue(&list, tmp->right, list->depth + 1);
		ft_dequeue(&list);
	}
}
