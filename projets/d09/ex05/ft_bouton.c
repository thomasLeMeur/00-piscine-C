/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bouton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 22:14:05 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/10 22:14:06 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		ft_bouton(int i, int j, int k)
{
	if (i > j)
		ft_swap(&i, &j);
	if (i > k)
		ft_swap(&i, &k);
	if (j > k)
		ft_swap(&j, &k);
	return (j);
}
