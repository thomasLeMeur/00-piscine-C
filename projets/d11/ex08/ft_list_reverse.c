/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 11:15:08 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 11:15:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		nb;
	t_list	*i;

	nb = 0;
	i = begin_list;
	if (i)
	{
		nb++;
		while (i->next)
		{
			i = i->next;
			nb++;
		}
	}
	return (nb);
}

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

void	ft_swap_elems(t_list **a, t_list **b)
{
	void	*tmp;

	tmp = (*a)->data;
	(*a)->data = (*b)->data;
	(*b)->data = tmp;
}

void	ft_list_reverse(t_list **begin_list)
{
	int		i;
	int		size;
	t_list	*a;
	t_list	*b;

	i = 0;
	size = ft_list_size(*begin_list);
	while (i < size / 2)
	{
		a = ft_list_at(*begin_list, i);
		b = ft_list_at(*begin_list, size - i - 1);
		ft_swap_elems(&a, &b);
		i++;
	}
}
