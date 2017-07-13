/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:50:03 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/15 11:50:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "strings.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_puterror(char *str)
{
	if (str)
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
	return (0);
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

int		g_neg_tmp;

int		ft_atoi(char *str, int *nb)
{
	int	i;
	int	pow;
	int	size;
	int	result;

	i = 1;
	pow = 1;
	result = 0;
	size = ft_strlen(str);
	g_neg_tmp = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	while (g_neg_tmp < size && (str[g_neg_tmp] >= '0' && str[g_neg_tmp] <= '9'))
		g_neg_tmp++;
	g_neg_tmp -= (str[0] == '-' || str[0] == '+') ? 1 : 0;
	while (i++ < g_neg_tmp)
		pow *= 10;
	g_neg_tmp = (size > 1 && str[0] == '-') ? -1 : 1;
	i = (g_neg_tmp == -1 || str[0] == '+') ? 1 : 0;
	while (i <= size)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (((*nb = result) || i == size) ? 1 : 0);
		result += (str[i++] - '0') * pow * g_neg_tmp;
		pow /= 10;
	}
	return (((*nb = result) || i == size) ? 1 : 0);
}
