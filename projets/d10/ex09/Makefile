#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/15 16:01:12 by tle-meur          #+#    #+#              #
#    Updated: 2015/09/15 16:01:13 by tle-meur         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = do-op

SRCS = main.c \
	ft_operators.c \
	ft_operations.c \
	ft_strings.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all
