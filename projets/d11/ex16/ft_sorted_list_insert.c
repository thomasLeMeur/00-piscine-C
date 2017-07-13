/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 17:57:52 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 17:57:53 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*i;
	t_list	*j;
	t_list	*new;

	i = *begin_list;
	new = ft_create_elem(data);
	if (!i)
		return ((void)(*begin_list = new));
	if ((*cmp)(i->data, data) > 0)
	{
		new->next = i;
		return ((void)(*begin_list = new));
	}
	j = i->next;
	while (j)
	{
		if ((*cmp)(j->data, data) > 0)
		{
			i->next = new;
			return ((void)(new->next = j));
		}
		i = j;
		j = j->next;
	}
	i->next = new;
}
