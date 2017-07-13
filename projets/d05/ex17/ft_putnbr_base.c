/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 13:55:30 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 13:55:31 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		size(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int		check_base(char *base, int size)
{
	int	i;
	int	alphabet[100];

	if (size <= 1)
		return (0);
	i = 0;
	while (i < 100)
		alphabet[i++] = 0;
	i = 1;
	while (i < size)
	{
		if (base[i] < ' ' || base[i] == 127 || base[i] == '-')
			return (0);
		if (base[i] == '+' || alphabet[base[i] - ' '] != 0)
			return (0);
		alphabet[base[i] - ' '] = 1;
		i++;
	}
	return (1);
}

void	print(char *nb, int size)
{
	while (size >= 0)
		ft_putchar(nb[size--]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		i;
	char	number[40];
	int		base_size;

	base_size = size(base);
	if (!check_base(base, base_size))
		return ;
	if (nbr == 0)
		ft_putchar(base[0]);
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	i = 0;
	while (nb != 0)
	{
		number[i++] = base[nb % base_size];
		nb /= base_size;
	}
	print(number, i - 1);
}
