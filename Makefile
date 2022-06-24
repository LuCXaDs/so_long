# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luserbu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 11:47:32 by luserbu           #+#    #+#              #
#    Updated: 2022/06/22 17:24:18 by luserbu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CC	 = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

LIBFT = libft/libft.a

PRINTF	= printf/libftprintf.a

all: ${NAME}

$(NAME): ${OBJS}
	ar rcs $(NAME) ${OBJS}

$(LIBFT) :
	make -C libft/

$(PRINTF) :
	make -C printf/

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	${RM} ${OBJS}
	make -C libft/ clean
	make -C printf/ clean

fclean: clean
	${RM} ${NAME}
	make -C libft/ fclean
	make -C printf/ clean

re: fclean all
.PHONY: clean all re
