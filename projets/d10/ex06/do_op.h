/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:58:11 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/15 11:58:12 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include "operations.h"

int		ft_get_operator(char *str, int *op);
void	ft_init_op(t_ptr_op *operations);
int		do_calcul(int n1, t_ptr_op op, int n2);
int		compute(int n1, int op, int n2);

#endif
