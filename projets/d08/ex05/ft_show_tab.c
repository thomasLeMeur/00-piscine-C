/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 12:26:56 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/14 12:26:57 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	ft_putchar('\n');
}

void	ft_putnbr(int nb)
{
	unsigned int	tmp;
	unsigned long	div;

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
		ft_putchar('0' + tmp / div);
		tmp %= div;
		div /= 10;
	}
	ft_putchar('\n');
}

void	ft_show_tab(t_stock_par *par)
{
	int	i;
	int	j;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].copy);
		ft_putnbr(par[i].size_param);
		j = 0;
		while (par[i].tab[j])
			ft_putstr(par[i].tab[j++]);
		i++;
	}
}
