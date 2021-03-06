/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 10:03:33 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/14 12:24:23 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*ptr;
	int		i;
	int		src_size;

	src_size = ft_strlen(src);
	ptr = (char*)malloc((src_size + 1) * sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i++ < src_size)
		ptr[i - 1] = src[i - 1];
	ptr[i - 1] = '\0';
	return (ptr);
}

void				ft_init(t_stock_par *elem, char *arg)
{
	if (arg)
	{
		elem->size_param = ft_strlen(arg);
		elem->str = arg;
		elem->copy = ft_strdup(arg);
		elem->tab = ft_split_whitespaces(arg);
	}
	else
	{
		elem->size_param = 0;
		elem->str = 0;
		elem->copy = NULL;
		elem->tab = NULL;
	}
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par	*result;

	i = 0;
	result = (t_stock_par*)malloc((ac + 1) * sizeof(t_stock_par));
	if (!result)
		return (NULL);
	while (i++ < ac)
		ft_init(&result[i - 1], av[i - 1]);
	ft_init(&result[i - 1], NULL);
	return (result);
}
