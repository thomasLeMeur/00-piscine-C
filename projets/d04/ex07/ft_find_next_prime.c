/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 14:38:46 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/07 14:38:48 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

int	ft_find_next_prime(int nb)
{
	int	j;
	int	sqrt;

	if (nb <= 2)
		return (2);
	nb = (nb % 2 == 0) ? nb + 1 : nb;
	while (nb)
	{
		j = 3;
		sqrt = ft_sqrt(nb);
		while (j <= sqrt)
		{
			if (nb % j == 0)
				break ;
			j += 2;
		}
		if (j >= sqrt)
			break ;
		nb += 2;
	}
	return (nb);
}
