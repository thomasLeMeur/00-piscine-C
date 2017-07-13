/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:58:07 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/15 11:58:08 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include "operations.h"

int		ft_get_operator(char *str, int *op)
{
	if (!str[0] || str[1])
		return (0);
	if (*str == '-')
		*op = LESS;
	else if (*str == '+')
		*op = PLUS;
	else if (*str == '*')
		*op = TIMES;
	else if (*str == '/')
		*op = DIV;
	else if (*str == '%')
		*op = MOD;
	else
		return (0);
	return (1);
}

void	ft_init_op(t_ptr_op *operations)
{
	operations[LESS] = &do_less;
	operations[PLUS] = &do_plus;
	operations[TIMES] = &do_times;
	operations[DIV] = &do_div;
	operations[MOD] = &do_mod;
}

int		do_calcul(int n1, t_ptr_op op, int n2)
{
	return (op(n1, n2));
}

int		compute(int n1, int op, int n2)
{
	t_ptr_op	operations[5];

	ft_init_op(operations);
	return (do_calcul(n1, operations[op], n2));
}
