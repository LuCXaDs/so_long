# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 11:47:32 by luserbu           #+#    #+#              #
#    Updated: 2022/08/24 15:07:01 by luserbu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCS	=	main.c \
			character.c \
			define.c \
			error.c \
			exit.c \
			maps.c \
			put_maps.c

SRCS_B	=	main_bonus.c \
			character_bonus.c \
			define_bonus.c \
			error_bonus.c \
			exit_bonus.c \
			maps_bonus.c \
			ennemy_bonus.c \
			put_maps_bonus.c
			

OBJS	= $(SRCS:.c=.o)
BONUS	= $(SRCS_B:.c=.o)
CC	 	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

LIBFT	= libft/libft.a

PRINTF	= printf/libftprintf.a

MLX		= mlx_linux/libmlx.a

all: ${NAME}

$(LIBFT) :
	make -sC libft/

$(PRINTF) :
	make -sC printf/

$(MLX) :
	make -sC mlx_linux/

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(LIBFT) $(PRINTF) $(MLX) $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

bonus: $(LIBFT) $(PRINTF) $(MLX) $(BONUS)
	$(CC) $(BONUS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

clean:
	${RM} ${OBJS} ${BONUS}
	make -sC libft/ clean
	make -sC printf/ clean
	make -sC mlx_linux/ clean

fclean: clean
	${RM} ${NAME}

re: fclean all
.PHONY: clean all re

.SILENT:
