/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:10:15 by luserbu           #+#    #+#             */
/*   Updated: 2022/06/17 20:10:17 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		verif_move_ennemy(t_data *data, int coord[2], int dir[2])
{
	if (data->maps[coord[0] + dir[0]][coord[1] + dir[1]] == '0'\
		|| data->maps[coord[0] + dir[0]][coord[1] + dir[1]] == 'P')
		return (1);
	return (0);
}

void	ft_put_ennemy(t_data *data, int coord[2], int dir[2])
{
	static int	i;

	if (++i/5)
	{
		data->maps[coord[0]][coord[1]] = 'M';
		if (data->cpt_frame_ene >= 4)
			data->cpt_frame_ene = 0;
		mlx_put_image_to_window(data->mlx, data->win,\
		data->frame_ene[data->cpt_frame_ene],\
		32*(coord[1]), 32 * (coord[0]));
		data->cpt_frame_ene++;
		if (verif_move_ennemy(data, coord, dir) == 1 && ++i/25)
		{
			i = 0;
			data->maps[coord[0]][coord[1]] = '0';
			data->maps[coord[0] + dir[0]][coord[1] + dir[1]] = 'M';
			mlx_put_image_to_window(data->mlx, data->win,\
			data->sprites.ennemy, 32*(coord[1] + dir[1]), 32*(coord[0] + dir[0]));
			mlx_put_image_to_window(data->mlx, data->win,\
			data->sprites.floor, 32*coord[1], 32*coord[0]);
			if (data->maps[data->cha_pos_x][data->cha_pos_y] == 'M')
				you_are_dead(data);
		}
	}
	
}

void	move_ennemy(t_data *data, int coord[2], int dir[2])
{
	int random;
	
	random = rand() % 4;
	if (random == 0)
	{
		dir[0] = -1;
		dir[1] = 0;
	}
	else if (random == 1)
	{
		dir[0] = 1;
		dir[1] = 0;
	}
	else if (random == 2)
	{
		dir[0] = 0;
		dir[1] = -1;
	}
	else if (random == 3)
	{
		dir[0] = 0;
		dir[1] = 1;
	}
	ft_put_ennemy(data, coord, dir);
}

int	read_maps_to_move_ennemy(t_data *data)
{
	int coord[2];
	int dir[2];

	coord[0] = data->ene_pos_x;
	coord[1] = data->ene_pos_y;
	dir[0] = 0;
	dir[1] = 0;
	while (data->maps[coord[0]])
	{
		coord[1] = 0;
		while (data->maps[coord[0]][coord[1]])
		{
			if (data->maps[coord[0]][coord[1]] == 'M')
			{
				move_ennemy(data, coord, dir);
				//frame_ennemy(data, coord, dir);
			}
			coord[1]++;
		}
		coord[0]++;
	}
	data->ene_pos_x = 0;
	data->ene_pos_y = 0;
	return (0);
}