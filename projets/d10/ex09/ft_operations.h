/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 17:01:18 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/15 17:21:28 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATIONS_H
# define FT_OPERATIONS_H

typedef	struct	s_opp
{
	char *op;
	void (*func)(int, int);
}				t_opp;

int				ft_get_op(char *str);
void			ft_do(int n1, int n2, void (*func)(int, int));
void			ft_compute(int n1, int n2, int op);
void			ft_usage(int a, int b);

#endif
