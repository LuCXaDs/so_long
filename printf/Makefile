# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luserbu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 17:59:44 by luserbu           #+#    #+#              #
#    Updated: 2022/04/27 18:19:09 by luserbu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	=	ft_printf.c\
			ft_putchar.c\
			ft_puthex_maj.c\
			ft_puthex_min.c\
			ft_putnbr.c\
			ft_putnbr_unsigned.c\
			ft_putstr.c\
			ft_putvoid.c
OBJS	= ${SRCS:.c=.o}
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f

all:	${NAME}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
.PHONY: clean all re
