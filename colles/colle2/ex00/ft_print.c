/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 09:47:32 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/20 13:43:58 by ntizio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_putnbr(int nb)
{
	long	tmp;
	long	div;

	tmp = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		tmp = -nb;
	}
	div = 1;
	while (div * 10 <= tmp)
		div *= 10;
	while (div)
	{
		ft_putchar(tmp / div + '0');
		tmp %= div;
		div /= 10;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print_result(t_col *liste, t_case caze)
{
	if (caze.lig <= 0)
		return (ft_putstr("aucune"));
	while (liste)
	{
		ft_putchar('[');
		ft_putstr(liste->name);
		ft_putstr("] [");
		ft_putnbr(caze.larg);
		ft_putstr("] [");
		ft_putnbr(caze.lig);
		ft_putchar(']');
		if (liste->next)
			ft_putstr(" || ");
		liste = liste->next;
	}
}
