/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 12:17:05 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/21 12:20:08 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H

# include "utilities.h"

# define MIN(x, y) ( ( (x) > (y) ) ? (y) : (x) )

int	compute(int **tab, t_rules *rules);
int	**init_tab(char *file, t_rules *rules);

#endif
