/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 11:58:55 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/21 17:15:33 by embailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/compute.h"
#include "../includes/ft_out.h"
#include "../includes/utilities.h"
#include "../includes/init_tab.h"

int	main(int ac, char **av)
{
	int		i;
	int		**tab;
	t_rules	rules;

	i = 1;
	tab = NULL;
	if (ac == 1)
	{
		//tab = init_tab_stdin(&rules);
		if (compute(tab, &rules))
			print_tab(tab, &rules);
		else
			ft_putstr("map error\n");
		free_tab(tab, &rules);
	}
	while (i < ac)
	{
		tab = init_tab(av[i++], &rules);
		if (compute(tab, &rules))
			print_tab(tab, &rules);
		else
			ft_putstr("map error\n");
		free_tab(tab, &rules);
	}
	return (0);
}
