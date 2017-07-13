/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 12:21:17 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/15 12:21:18 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	do_plus(int a, int b)
{
	return (a + b);
}

int	do_less(int a, int b)
{
	return (a - b);
}

int	do_times(int a, int b)
{
	return (a * b);
}

int	do_div(int a, int b)
{
	if (!b)
		return (0);
	return (a / b);
}

int	do_mod(int a, int b)
{
	if (!b)
		return (0);
	return (a % b);
}
