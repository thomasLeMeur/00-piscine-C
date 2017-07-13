/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 16:35:18 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/15 16:35:19 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "ft_operations.h"

int	main(int ac, char **av)
{
	int		n1;
	int		n2;
	int		op;

	if (ac != 4)
		return (0);
	n1 = ft_atoi(av[1], 0, 0);
	op = ft_get_op(av[2]);
	n2 = ft_atoi(av[3], 0, 0);
	ft_compute(n1, n2, op);
	return (0);
}
