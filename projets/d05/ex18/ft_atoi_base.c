/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 16:33:08 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 16:33:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base, int base_size)
{
	int	i;
	int	alphabet[100];

	if (base_size <= 1)
		return (0);
	i = 0;
	while (i < 100)
		alphabet[i++] = 0;
	i = 1;
	while (i < base_size)
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

int	check_str(char *str, int str_size, char *base, int base_size)
{
	int	i;
	int	j;

	if (str_size <= 1 || str_size > 35)
		return (0);
	i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	while (i < str_size)
	{
		j = 0;
		while (base[j] != '\0' && str[i] != base[j])
			j++;
		if (j == base_size && str[i] != base[j - 1])
			return (0);
		i++;
	}
	return (1);
}

int	chgmt_base(char *nbr, int nbr_size, char *base, int base_size)
{
	long	nb;
	long	pow;
	int		i;
	int		id;

	nb = 0;
	i = nbr_size - 1;
	pow = 1;
	while (i >= 0)
	{
		id = 0;
		if (nbr[i] == '-' || nbr[i] == '+')
			break ;
		while (nbr[i] != base[id])
			id++;
		nb += id * pow;
		pow *= base_size;
		i--;
	}
	if (nb != (int)nb)
		return (0);
	return ((nbr[0] == '-') ? -nb : nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int		base_size;

	base_size = ft_strlen(base);
	if (!check_base(base, base_size))
		return (0);
	if (!check_str(str, ft_strlen(str), base, base_size))
		return (0);
	return (chgmt_base(str, ft_strlen(str), base, base_size));
}
