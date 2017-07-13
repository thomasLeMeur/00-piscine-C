/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:43:04 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/15 11:43:06 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include "strings.h"
#include "operations.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	int			n1;
	int			n2;
	int			op;

	if (ac != 4)
		return (0);
	if (!ft_get_operator(av[2], &op))
		return (ft_puterror("0"));
	ft_atoi(av[1], &n1);
	ft_atoi(av[3], &n2);
	if (n2 == 0)
	{
		if (op == DIV)
			return (ft_puterror(ZERODIV));
		else if (op == MOD)
			return (ft_puterror(ZEROMOD));
	}
	ft_putnbr(compute(n1, op, n2));
	return (0);
}
