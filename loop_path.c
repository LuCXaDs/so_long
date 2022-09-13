/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:29:34 by luserbu           #+#    #+#             */
/*   Updated: 2022/09/04 20:08:45 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_up_found_path(int x, int y, t_path *path)
{
	if (path->maps[x + 1][y] == '0' || path->maps[x + 1][y] == 'C'
		|| path->maps[x + 1][y] == 'E')
	{
		if (path->maps[x + 1][y] != 'E')
		{
			path->pass[path->roll_back] = path->plan[x][y];
			path->roll_back++;
			path->maps[x][y] = 'A';
			x++;
			path->cha_pos_x = x;
			if (path->maps[x][y] == 'C')
				path->nb_coin--;
		}
		else
		{
			path->maps[x + 1][y] = '1';
			path->nb_ext--;
		}
		return (1);
	}
	return (0);
}

int	loop_down_found_path(int x, int y, t_path *path)
{
	if (path->maps[x - 1][y] == '0' || path->maps[x - 1][y] == 'C'
		|| path->maps[x - 1][y] == 'E')
	{
		if (path->maps[x - 1][y] != 'E')
		{
			path->pass[path->roll_back] = path->plan[x][y];
			path->roll_back++;
			path->maps[x][y] = 'A';
			x--;
			path->cha_pos_x = x;
			if (path->maps[x][y] == 'C')
				path->nb_coin--;
		}
		else
		{
			path->maps[x - 1][y] = '1';
			path->nb_ext--;
		}
		return (1);
	}
	return (0);
}

int	loop_left_found_path(int x, int y, t_path *path)
{
	if (path->maps[x][y - 1] == '0' || path->maps[x][y - 1] == 'C'
		|| path->maps[x][y - 1] == 'E')
	{
		if (path->maps[x][y - 1] != 'E')
		{
			path->pass[path->roll_back] = path->plan[x][y];
			path->roll_back++;
			path->maps[x][y] = 'A';
			y--;
			path->cha_pos_y = y;
			if (path->maps[x][y] == 'C')
				path->nb_coin--;
		}
		else
		{
			path->maps[x][y - 1] = '1';
			path->nb_ext--;
		}
		return (1);
	}
	return (0);
}

int	loop_right_found_path(int x, int y, t_path *path)
{
	if (path->maps[x][y + 1] == '0' || path->maps[x][y + 1] == 'C'
		|| path->maps[x][y + 1] == 'E')
	{
		if (path->maps[x][y + 1] != 'E')
		{
			path->pass[path->roll_back] = path->plan[x][y];
			path->roll_back++;
			path->maps[x][y] = 'A';
			y++;
			path->cha_pos_y = y;
			if (path->maps[x][y] == 'C')
				path->nb_coin--;
		}
		else
		{
			path->maps[x][y + 1] = '1';
			path->nb_ext--;
		}
		return (1);
	}
	return (0);
}
