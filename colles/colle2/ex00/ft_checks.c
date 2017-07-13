/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 11:41:23 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/20 21:43:47 by ntizio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checks.h"

int	check_first_line(t_col *colle, t_case *caze, char *c)
{
	if (caze->col == 0 && c[1] == 0)
	{
		if (c[0] == colle->syms[TL])
			colle->occu[TL]++;
		else
			return (0);
	}
	if (caze->col > 0)
	{
		if (c[0] != colle->syms[TR] && c[0] != colle->syms[TB])
			return (0);
		if (c[0] == colle->syms[TR])
		{
			if (colle->occu[TR] == 0)
				colle->occu[TR]++;
			else
				return (0);
		}
		if ((c[0] == '\n' || c[0] == '\0') && c[1] != colle->syms[TR])
			return (0);
	}
	return (1);
}

int	check_first_col(t_col *colle, char *c)
{
	if (c[1] == '\n' && c[0] != colle->syms[BL] && c[0] != colle->syms[LR])
		return (0);
	if (c[0] == colle->syms[BL])
	{
		if (colle->occu[BL] == 0)
			colle->occu[BL]++;
		else
			return (0);
	}
	if (c[0] == colle->syms[LR])
		colle->occu[LR]++;
	return (1);
}

int	check_last_col(t_col *colle, char *c)
{
	if (c[0] == '\n')
	{
		if (c[1] != colle->syms[LR])
			if (c[1] != colle->syms[BR] && c[1] != colle->syms[BL])
				return (0);
		colle->occu[LR] = 0;
	}
	return (1);
}

int	check(t_col *colle, t_case *caze, char *c)
{
	if (caze->lig == 0)
		return (check_first_line(colle, caze, c));
	if ((caze->col == 0 && caze->lig == 1) || (caze->col == 1 && caze->lig > 1))
		return (check_first_col(colle, c));
	if (c[0] == colle->syms[LR])
		colle->occu[LR]++;
	if (colle->occu[LR] > 2 || !check_last_col(colle, c))
		return (0);
	if (c[0] == colle->syms[BR])
	{
		if (colle->occu[BR] == 0)
			colle->occu[BR]++;
		else
			return (0);
	}
	if (c[0] == '\n')
		colle->occu[LR] = 0;
	if (colle->occu[BL])
		if (c[0] != '\n' && c[0] != colle->syms[TB] && c[0] != colle->syms[BR])
			return (0);
	if (colle->occu[BL] == 0)
		if (c[0] != '\n' && c[0] != ' ' && c[0] != colle->syms[LR])
			return (0);
	return (1);
}
