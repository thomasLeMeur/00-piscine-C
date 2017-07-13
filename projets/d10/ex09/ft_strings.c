/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 16:19:12 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/15 16:19:13 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

int		ft_atoi(char *str, int nb, int sig)
{
	if (!str)
		return (0);
	if (*str == '-' && nb == 0 && sig == 0)
		return (ft_atoi(str + 1, nb, -1));
	if (*str == '+' && nb == 0 && sig == 0)
		return (ft_atoi(str + 1, nb, 1));
	if (!*str || *str < '0' || *str > '9')
		return (nb);
	sig = (sig == 0) ? 1 : sig;
	return (ft_atoi(str + 1, 10 * nb + sig * (*str - '0'), sig));
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

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
