/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 23/06/26 11:21:35 by luserbu           #+#    #+#               */
/*   Updated: 22/06/15 18:08:39 by luserbu          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_move(t_data *data, int coord[2], int dir[2])
{
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
	if (verif_move(data, coord, dir) == 1)
	{
		data->move += 1;
		data->cha_pos_x += dir[0];
		data->cha_pos_y += dir[1];
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.floor, 32
			* coord[1], 32 * coord[0]);
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.character,
			32 * (coord[1] + dir[1]), 32 * (coord[0] + dir[0]));
		ft_printf("Mouvement %d\n", data->move);
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
