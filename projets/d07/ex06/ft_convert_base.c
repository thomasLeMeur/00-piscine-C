/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 16:10:40 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/10 16:10:42 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		pgd(char *str, char *base)
{
	int	str_size;
	int	base_size;
	int	div;

	str_size = ft_strlen(str);
	base_size = ft_strlen(base);
	div = 1;
	while (str_size-- > 1)
		div *= base_size;
	return (div);
}

void	int_to_base(int nb, char *result, char *base)
{
	int		i;
	int		div;
	int		base_size;
	int		result_size;
	char	tmp;

	div = 1;
	i = 0;
	base_size = ft_strlen(base);
	while (nb != 0)
	{
		result[i++] = base[nb % base_size];
		nb /= base_size;
	}
	i = 0;
	result_size = ft_strlen(result);
	while (i < result_size / 2)
	{
		tmp = result[i++];
		result[i - 1] = result[result_size - i];
		result[result_size - i] = tmp;
	}
}

int		base_to_int(char *nbr, char *base)
{
	int	i;
	int	nb;
	int	div;
	int	is_neg;
	int	id_case;

	nb = 0;
	div = pgd(nbr, base);
	is_neg = (nbr[0] == '-') ? -1 : 1;
	i = (nbr[0] == '-' || nbr[0] == '+') ? 1 : 0;
	while (i++ < ft_strlen(nbr))
	{
		id_case = 0;
		while (nbr[i - 1] != base[id_case])
			id_case++;
		nb += is_neg * div * id_case;
		div /= ft_strlen(base);
	}
	return (nb);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*result;

	if (nbr[0] == '\0')
		return (NULL);
	nb = 0;
	result = (char*)malloc(35 * sizeof(*result));
	while (nb < 35)
		result[nb++] = '\0';
	nb = base_to_int(nbr, base_from);
	int_to_base(nb, result, base_to);
	return (result);
}
