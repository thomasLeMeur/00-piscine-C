/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 14:11:13 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/11 14:11:23 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	int				i;
	int				cmp;
	unsigned int	nb;

	i = 0;
	nb = 0;
	cmp = 1;
	while (i < 4 * 8)
	{
		if (value & cmp)
			nb++;
		cmp <<= 1;
		i++;
	}
	return (nb);
}
