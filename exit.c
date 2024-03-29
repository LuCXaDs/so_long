/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:21:35 by serbu             #+#    #+#             */
/*   Updated: 2022/09/05 18:09:51 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx, data->sprites.character);
	mlx_destroy_image(data->mlx, data->sprites.floor);
	mlx_destroy_image(data->mlx, data->sprites.wall_left);
	mlx_destroy_image(data->mlx, data->sprites.wall_right);
	mlx_destroy_image(data->mlx, data->sprites.wall_down);
	mlx_destroy_image(data->mlx, data->sprites.wall_up);
	mlx_destroy_image(data->mlx, data->sprites.wall_c_t_l);
	mlx_destroy_image(data->mlx, data->sprites.wall_c_t_r);
	mlx_destroy_image(data->mlx, data->sprites.wall_c_b_l);
	mlx_destroy_image(data->mlx, data->sprites.wall_c_b_r);
	mlx_destroy_image(data->mlx, data->sprites.chest);
	mlx_destroy_image(data->mlx, data->sprites.exit);
	mlx_destroy_image(data->mlx, data->sprites.block);
}

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
	if (nb == 0)
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

int	ft_exit_error(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->mapx)
		free(data->maps[i]);
	free(data->maps);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	ft_close(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->mapx)
	{
		free(data->maps[i]);
		i++;
	}
	free(data->maps);
	free_sprites(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
