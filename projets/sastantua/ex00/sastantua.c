/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 13:21:28 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/04 13:21:31 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_spaces(int larg_max, int larg, int i)
{
	while (i++ < (larg_max - (larg + 2)) / 2)
		ft_putchar(' ');
}

void	print_door(int *i, int line, int size, int floor_max)
{
	int	j;

	j = 0;
	while (j++ < size)
		ft_putchar((line == (size + 1) / 2 && j == size - 1 \
			&& floor_max >= 5) ? '$' : '|');
	*i += j - 2;
}

void	print_line(int larg, int line, int floor, int floor_max)
{
	int	i;
	int	door;
	int	door_size;
	int	deb_door;

	i = 0;
	door_size = (floor % 2 == 0) ? floor - 1 : floor;
	deb_door = (larg - 1) / 2 - door_size / 2 + 1;
	door = (floor == floor_max && line > (2 + floor) - door_size) ? 1 : 0;
	ft_putchar('/');
	while (i++ < larg)
		if (door && i == deb_door)
			print_door(&i, line - (floor_max % 2 ? 2 : 3), door_size, floor_max);
		else
			ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

int		print_floor(int id_floor, int floor_max, int larg_max)
{
	int	i;
	int	larg_line;

	if (id_floor <= 0)
		return (0);
	larg_line = print_floor(id_floor - 1, floor_max, larg_max);
	larg_line += (id_floor == 1) ? 1 : (3 + (id_floor - 2) / 2) * 2;
	i = 0;
	while (i++ < 2 + id_floor)
	{
		print_spaces(larg_max, larg_line, 0);
		print_line(larg_line, i, id_floor, floor_max);
		larg_line += 2;
	}
	return (larg_line - 2);
}

void	sastantua(int size)
{
	int	i;
	int	nb_lines;
	int	larg_max;

	i = 0;
	nb_lines = 2;
	larg_max = 3;
	while (++i < size)
	{
		nb_lines += 2 + i;
		larg_max += (3 + (i - 1) / 2) * 2;
	}
	larg_max += 2 + (nb_lines - 1) * 2;
	print_floor(size, size, larg_max);
}

/*
 *	Prog de test
 */
#include <stdlib.h>
#include <unistd.h>
void	ft_putchar(char c) { write(1, &c, 1); }
int		main(int ac, char **av) { if (ac > 1) sastantua(atoi(av[1])); }
