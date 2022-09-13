/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   criss_cross_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:38:39 by luserbu           #+#    #+#             */
/*   Updated: 2022/09/05 16:00:28 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	copy_maps(t_data *data, t_path *path);
void	check_element_maps(t_data *data, t_path *path);
void	maps_plan(t_data *data, t_path *path);

void	check_path(t_data *data, t_path *path)
{
	copy_maps(data, path);
	check_element_maps(data, path);
	maps_plan(data, path);
	found_path(data, path);
}

void	copy_maps(t_data *data, t_path *path)
{
	int	i;

	i = 0;
	path->maps = malloc(sizeof(char *) * data->mapx);
	while (data->maps[i])
	{
		path->maps[i] = ft_strdup(data->maps[i]);
		i++;
	}
}

void	check_element_maps(t_data *data, t_path *path)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data->mapx - 1)
	{
		j = 0;
		while (j <= data->mapy - 1)
		{
			if (path->maps[i][j] == '0')
				path->nb_floor++;
			if (path->maps[i][j] == 'P')
			{
				path->cha_pos_x = i;
				path->cha_pos_y = j;
			}
			if (path->maps[i][j] == 'E')
				path->nb_ext++;
			if (path->maps[i][j] == 'C')
				path->nb_coin++;
			j++;
		}
		i++;
	}
}

void	maps_plan(t_data *data, t_path *path)
{
	int	i;
	int	j;
	int	cmpt;

	i = 0;
	cmpt = 0;
	path->plan = malloc(sizeof(char *) * data->mapx);
	while (i <= data->mapx - 1)
	{
		path->plan[i] = malloc(sizeof(char *) * data->mapy - 1);
		j = 0;
		while (j <= data->mapy - 1)
		{
			path->plan[i][j] = cmpt;
			j++;
			cmpt++;
		}
		i++;
	}
}

void	verif_player_position(t_data *data, t_path *path)
{
	int	x;
	int	y;
	int	error;

	x = path->cha_pos_x;
	y = path->cha_pos_y;
	error = 0;
	if (path->maps[x + 1][y] == '1')
		error++;
	if (path->maps[x - 1][y] == '1')
		error++;
	if (path->maps[x][y + 1] == '1')
		error++;
	if (path->maps[x][y - 1] == '1')
		error++;
	if (error == 4)
		exit_path(data, path, 0);
}
