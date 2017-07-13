/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 10:13:42 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/20 18:39:27 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# define TL 0
# define TR 1
# define BL 2
# define BR 3
# define TB 4
# define LR 5

# include <stdlib.h>

typedef	struct s_col	t_col;
typedef	struct s_case	t_case;

struct	s_col
{
	char	*name;
	char	*syms;
	int		occu[6];
	t_col	*next;
};

struct	s_case
{
	int	lig;
	int	col;
	int	larg;
};

void	free_liste(t_col **liste);
void	init_liste(t_col **liste);
void	verification(t_col **liste, t_case *caze, char *c);
void	init_elem(t_col **elem, char *name, char *syms);

#endif
