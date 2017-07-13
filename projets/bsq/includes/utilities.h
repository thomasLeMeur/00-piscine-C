/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 12:21:46 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/21 13:06:30 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

typedef	struct	s_rules
{
	int		nb_lig;
	int		nb_col;
	int		max;
	int		x_max;
	int		y_max;
	char	vide;
	char	obstacle;
	char	plein;
}				t_rules;

long long		ft_atoi(char *str, int nb, int sig);
char			*ft_realloc(char *src, int *size);
void			free_tab(int **tab, t_rules *rules);
int				*ft_strdup(char *buffer, t_rules *rules);
void			fill_result(int **tab, t_rules *rules);

#endif
