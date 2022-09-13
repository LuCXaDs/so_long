# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 11:47:32 by luserbu           #+#    #+#              #
#    Updated: 2022/09/04 20:00:28 by luserbu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCS	=	main.c \
			character.c \
			define.c \
			error.c \
			exit.c \
			maps.c \
			put_maps.c \
			check_path.c \
			criss_cross.c \
			loop_path.c

SRCS_B	=	bonus/main_bonus.c \
			bonus/character_bonus.c \
			bonus/define_bonus.c \
			bonus/error_bonus.c \
			bonus/exit_bonus.c \
			bonus/maps_bonus.c \
			bonus/ennemy_bonus.c \
			bonus/put_maps_bonus.c \
			bonus/check_path_bonus.c \
			bonus/criss_cross_bonus.c \
			bonus/loop_path_bonus.c \
			bonus/exit_path_bonus.c
			

OBJS	= $(SRCS:.c=.o)
BONUS	= $(SRCS_B:.c=.o)
CC	 	= gcc -g
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
