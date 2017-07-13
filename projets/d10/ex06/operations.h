/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 12:21:20 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/15 12:21:21 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# define ZERODIV "Stop : division by zero"
# define ZEROMOD "Stop : modulo by zero"

typedef	int	(*t_ptr_op)(int, int);

enum {LESS, PLUS, TIMES, DIV, MOD};

int	do_plus(int a, int b);
int	do_less(int a, int b);
int	do_times(int a, int b);
int	do_div(int a, int b);
int	do_mod(int a, int b);

#endif
