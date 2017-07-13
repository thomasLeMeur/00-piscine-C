/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 10:02:41 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/07 10:03:01 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0 || nb >= 13)
		return (0);
	result = (nb == 0) ? 1 : nb;
	while (--nb >= 1)
		result *= nb;
	return (result);
}
