/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 11:07:28 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 11:07:29 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	nb;
	t_list			*i;

	nb = 0;
	i = begin_list;
	if (i)
		while (nb < nbr && i->next)
		{
			nb++;
			i = i->next;
		}
	if (nb == nbr && i)
		return (i);
	else
		return (NULL);
}
