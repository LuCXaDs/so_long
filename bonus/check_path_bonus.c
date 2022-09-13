/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:59:47 by luserbu           #+#    #+#             */
/*   Updated: 2022/09/04 20:12:56 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		player_roll_back(t_data *data, t_path *path);

void	found_path(t_data *data, t_path *path)
{
	int	x;
	int	y;

	path->pass = malloc(sizeof(int) * (path->nb_coin + path->nb_floor
				+ path->nb_ext + 2));
	while (path->nb_coin != 0 || path->nb_ext != 0)
	{
		x = path->cha_pos_x;
		y = path->cha_pos_y;
		if (loop_up_found_path(x, y, path) == 0 && loop_down_found_path(x, y,
				path) == 0 && loop_left_found_path(x, y, path) == 0
			&& loop_right_found_path(x, y, path) == 0)
		{
			path->maps[x][y] = '1';
			if (player_roll_back(data, path) == 0)
				exit_path(data, path, 0);
			x = path->cha_pos_x;
			y = path->cha_pos_y;
			path->roll_back--;
			verif_player_position(data, path);
		}
	}
}

int	player_roll_back(t_data *data, t_path *path)
{
	int	x;
	int	y;
	int	before;

	x = 0;
	if (path->roll_back == 0)
		return (0);
	while (x <= data->mapx - 1)
	{
		y = 0;
		while (y <= data->mapy - 1)
		{
			before = path->plan[x][y];
			if (path->pass[path->roll_back - 1] == before)
			{
				path->cha_pos_x = x;
				path->cha_pos_y = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (1);
}
