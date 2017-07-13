/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 13:43:39 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/13 13:43:40 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

# include <unistd.h>

int		put_error(void);
void	ft_putstr(char *str);
int		check_arg(char *str);
void	ft_strcpy(char *s1, char *s2);

#endif
