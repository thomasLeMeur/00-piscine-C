#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/15 14:00:02 by tle-meur          #+#    #+#              #
#    Updated: 2015/09/15 14:00:03 by tle-meur         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = do-op

SRCS = main.c do_op.c operations.c strings.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I . -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all
