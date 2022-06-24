# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luserbu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 10:57:15 by luserbu           #+#    #+#              #
#    Updated: 2022/04/15 15:38:56 by luserbu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
SRCS    = $(wildcard *.c)
OBJS    = ${SRCS:.c=.o}
CC  = gcc
CFLAGS	= -Wall -Wextra -Werror
RM      = rm -f

all:	${NAME}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
.PHONY: clean all re
