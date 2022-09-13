/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:21:35 by serbu             #+#    #+#             */
/*   Updated: 2022/08/23 17:10:43 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	frames(t_data *data)
{
	static int	i;
	static int	frame_cha;

	if (++i / 2)
	{
		i = 0;
		mlx_put_image_to_window(data->mlx, data->win,
			data->frame_char[frame_cha], 32 * data->cha_pos_y, 32
			* data->cha_pos_x);
		frame_cha++;
		if (frame_cha >= 9)
			frame_cha = 0;
	}
	read_maps_to_move_ennemy(data);
	usleep(1000000 / 30);
	return (0);
}

int	verif_move(t_data *data, int coord[2], int dir[2])
{
	if (data->maps[coord[0] + dir[0]][coord[1] + dir[1]] == 'M')
		win_or_lose(data, 0);
	if (data->maps[coord[0] + dir[0]][coord[1] + dir[1]] == '0'
		|| data->maps[coord[0] + dir[0]][coord[1] + dir[1]] == 'C'
		|| data->maps[coord[0] + dir[0]][coord[1] + dir[1]] == 'P')
		return (1);
	if (data->coin == 0
		&& data->maps[coord[0] + dir[0]][coord[1] + dir[1]] == 'E')
		return (1);
	return (0);
}

void	ft_move(t_data *data, int coord[2], int dir[2])
{
	char	*str;

	if (verif_move(data, coord, dir) == 1)
	{
		data->move += 1;
		data->cha_pos_x += dir[0];
		data->cha_pos_y += dir[1];
		str = ft_itoa(data->move);
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.floor, 32
			* coord[1], 32 * coord[0]);
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.character,
			32 * (coord[1] + dir[1]), 32 * (coord[0] + dir[0]));
		ft_printf("Mouvement %d\n", data->move);
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites.wall_up_move00, 32, 0);
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites.wall_up_move01, 64, 0);
		mlx_string_put(data->mlx, data->win, 40, 25, 0xffffff, "MOVE");
		mlx_string_put(data->mlx, data->win, 70, 25, 0xffffff, str);
		free(str);
		collect_and_close(data);
	}
}

void	move_character(int keycode, t_data *data, int coord[2], int dir[2])
{
	if (keycode == 'w')
	{
		dir[0] = -1;
		dir[1] = 0;
		ft_move(data, coord, dir);
	}
	else if (keycode == 's')
	{
		dir[0] = 1;
		dir[1] = 0;
		ft_move(data, coord, dir);
	}
	else if (keycode == 'a')
	{
		dir[0] = 0;
		dir[1] = -1;
		ft_move(data, coord, dir);
	}
	else if (keycode == 'd')
	{
		dir[0] = 0;
		dir[1] = 1;
		ft_move(data, coord, dir);
	}
}

int	define_move_character(int keycode, t_data *data)
{
	int	coord[2];
	int	dir[2];

	coord[0] = data->cha_pos_x;
	coord[1] = data->cha_pos_y;
	dir[0] = 0;
	dir[1] = 0;
	if (keycode == 65307)
		ft_close(data);
	move_character(keycode, data, coord, dir);
	return (0);
}
