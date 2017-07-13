/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 17:12:16 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 17:12:17 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list **begin_list2)
{
	t_list *i;

	i = *begin_list1;
	if (!i)
		*begin_list1 = *begin_list2;
	else
	{
		while (i->next)
			i = i->next;
		i->next = *begin_list2;
	}
}
