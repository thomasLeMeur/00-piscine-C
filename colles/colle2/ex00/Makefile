#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/20 20:56:30 by tle-meur          #+#    #+#              #
#    Updated: 2015/09/20 21:09:09 by tle-meur         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		colle-2

SRCS=		main.c utilities.c ft_print.c ft_checks.c

OBJS=		main.o utilities.o ft_print.o ft_checks.o

FLAGS=		-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):
			gcc $(FLAGS) -c $(SRCS)
			gcc -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all