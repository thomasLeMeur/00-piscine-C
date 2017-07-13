/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 11:28:00 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/20 11:28:01 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKS_H
# define FT_CHECKS_H

# include "utilities.h"

int	check_first_line(t_col *colle, t_case *caze, char *c);
int	check_first_col(t_col *colle, char *c);
int	check_last_col(t_col *colle, char *c);
int	check(t_col *colle, t_case *caze, char *c);

#endif
