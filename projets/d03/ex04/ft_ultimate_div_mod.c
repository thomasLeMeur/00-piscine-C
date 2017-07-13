/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 11:56:27 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/04 11:56:29 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div_tmp;
	int	mod_tmp;

	div_tmp = *a / *b;
	mod_tmp = *a % *b;
	*a = div_tmp;
	*b = mod_tmp;
}
