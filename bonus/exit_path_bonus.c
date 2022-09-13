/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_path_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:53:04 by luserbu           #+#    #+#             */
/*   Updated: 2022/09/05 15:02:55 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_path(t_data *data, t_path *path, int nb)
{
	int	i;

	i = -1;
	while (++i < data->mapx)
		free(path->maps[i]);
	free(path->maps);
	i = -1;
	while (++i < data->mapx)
		free(path->plan[i]);
	free(path->plan);
	free(path->pass);
	if (nb == 0 || nb == 2)
	{
		i = -1;
		while (++i < data->mapx)
			free(data->maps[i]);
		free(data->maps);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_printf("Error\n/* Path not found */\n");
		exit(0);
	}
}
