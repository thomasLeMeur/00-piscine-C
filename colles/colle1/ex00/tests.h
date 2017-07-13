/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 13:45:44 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/13 13:45:45 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

int	test_lig(char **grille, int lig, int nb);
int	test_col(char **grille, int col, int nb);
int	test_case(char **grille, int lig, int col, int nb);
int	test_square(char **grille, int lig, int col, int nb);

#endif
