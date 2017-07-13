/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 19:11:23 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 19:11:25 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list2_to_begin(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	t_list	*i1;
	t_list	*i2;
	t_list	*tmp;

	i1 = *begin_list1;
	i2 = begin_list2;
	if ((*cmp)(i1->data, i2->data) > 0)
	{
		tmp = i2;
		i2 = i2->next;
		tmp->next = i1;
		*begin_list1 = tmp;
	}
	while (i2 && (*cmp)(i1->data, i2->data) > 0)
	{
		tmp->next = i2;
		i2 = i2->next;
		tmp = tmp->next;
	}
	tmp->next = i1;
	return (i2);
}

void	ft_crossed_sort(t_list **i1, t_list **j, t_list **i2, int (*cmp)())
{
	while (*j && *i2)
	{
		while (*j && *i2 && (*cmp)((*j)->data, (*i2)->data) > 0)
		{
			(*i1)->next = *i2;
			*i1 = *i2;
			*i2 = (*i2)->next;
			(*i1)->next = *j;
		}
		*i1 = *j;
		*j = (*j)->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	t_list	*i1;
	t_list	*i2;
	t_list	*j;

	i1 = *begin_list1;
	i2 = begin_list2;
	if (!i1)
		return ((void)(*begin_list1 = begin_list2));
	if (!i2)
		return ;
	i2 = ft_list2_to_begin(begin_list1, begin_list2, cmp);
	j = i1->next;
	ft_crossed_sort(&i1, &j, &i2, cmp);
	if (!j)
		i1->next = i2;
}
