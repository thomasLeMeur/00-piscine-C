#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 11:53:57 by tle-meur          #+#    #+#              #
#    Updated: 2015/09/21 11:57:59 by tle-meur         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		bsq

SRCS=		srcs/*.c

FLAGS=		-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	
			gcc  $(FLAGS) -o $(NAME) $(SRCS)

clean:
			rm -f $(NAME)

fclean:			clean

re:			fclean all
