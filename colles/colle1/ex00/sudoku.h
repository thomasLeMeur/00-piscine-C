/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 13:47:44 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/13 13:47:45 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include "tests.h"
# include "memory.h"

char	**resolve(char **grille, int lig, int col, char **solution);
char	**fill_case(char **grille, int lig, int col, char **solution);

#endif
