/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 19:35:50 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/10 19:35:52 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int		hour_;
	int		n_hour;
	char	d;
	char	f;

	hour_ = (hour % 12 == 0) ? 12 : hour % 12;
	n_hour = ((hour + 1) % 12 == 0) ? 12 : (hour + 1) % 12;
	d = (hour < 12) ? 'A' : 'P';
	f = ((hour + 1 < 12 && hour + 1 > 0) || hour + 1 == 24) ? 'A' : 'P';
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00 %c.M. AND %d.00 %c.M.\n", hour_, d, n_hour, f);
}
