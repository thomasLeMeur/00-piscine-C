/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 09:54:25 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/17 09:54:26 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	print_file(char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "File doesn't exist.\n", 20);
	}
	else
	{
		while (read(fd, &c, 1))
			write(1, &c, 1);
		if (close(fd) == -1)
			write(2, "File doesn't want to close.\n", 27);
	}
}

int		main(int ac, char **av)
{
	if (ac < 2)
		write(1, "File name missing.\n", 19);
	else if (ac > 2)
		write(1, "Too many arguments.\n", 20);
	else
		print_file(av[1]);
	return (0);
}
