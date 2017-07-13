/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 10:48:01 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 10:48:02 by tle-meur         ###   ########.fr       */
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

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*new;

	i = 1;
	new = NULL;
	while (i < ac)
		ft_list_push_front(&new, av[i++]);
	return (new);
}
