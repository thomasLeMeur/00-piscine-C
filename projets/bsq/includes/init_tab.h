/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 18:52:53 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/21 18:52:54 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_TAB_H
# define INIT_TAB_H

# include "utilities.h"
# include <unistd.h>
# include <fcntl.h>

char	*read_instructions(int fd);
int		init_rules(char *buf, t_rules *rules);
char	*read_first_line(int fd, t_rules *rules);
int		check_line_and_copy(int fd, int *lig, t_rules *rules);

#endif
