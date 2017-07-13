/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 17:34:19 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/03 17:34:24 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int	unite;

	if (nb < 0)
	{
		ft_putchar('-');
	}
	while (nb != 0 && nb != -0)
	{
		unite = nb % 10;
		if (unite < 0)
		{
			unite = -unite;
		}
		ft_putchar('0' + unite);
		nb /= 10;
	}
}
