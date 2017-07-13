/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 10:22:49 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 10:22:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *i;
	t_list *new;

	i = *begin_list;
	if (i)
	{
		new = ft_create_elem(data);
		new->next = i;
		*begin_list = new;
	}
	else
		*begin_list = ft_create_elem(data);
}
