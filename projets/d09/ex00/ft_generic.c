/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 19:20:58 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/10 19:21:00 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	tu(void)
{
	char str[10];

	str[0] = 'u';
	str[1] = ' ';
	str[2] = 't';
	str[3] = 'u';
	str[4] = ' ';
	str[5] = 't';
	str[6] = 'u';
	str[7] = ' ';
	str[8] = 't';
	str[9] = 'u';
	write(1, &str, 10);
}

void	ft_generic(void)
{
	char inter[3];
	char c1;
	char c2;

	inter[0] = ' ';
	inter[1] = ';';
	inter[2] = ' ';
	c1 = 'T';
	c2 = '\n';
	write(1, &c1, 1);
	tu();
	write(1, &inter, 3);
	write(1, &c1, 1);
	tu();
	write(1, &c2, 1);
}
