/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 18:12:40 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/15 18:12:41 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operators.h"
#include "ft_strings.h"

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_mul(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_div(int a, int b)
{
	if (!b)
		ft_putstr(ZERODIV);
	else
		ft_putnbr(a / b);
}

void	ft_mod(int a, int b)
{
	if (!b)
		ft_putstr(ZEROMOD);
	else
		ft_putnbr(a % b);
}
