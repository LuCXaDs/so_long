/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:31:30 by luserbu           #+#    #+#             */
/*   Updated: 2022/06/15 18:46:07 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	define_other_sprites(t_data *data)
{
	int	width;
	int	height;

	data->sprites.floor = mlx_xpm_file_to_image(data->mlx, \
	"asset/floor01.xpm", &width, &height);
	data->sprites.character = mlx_xpm_file_to_image(data->mlx, \
	"asset/character01.xpm", &width, &height);
	data->sprites.chest = mlx_xpm_file_to_image(data->mlx, \
	"asset/chest.xpm", &width, &height);
	data->sprites.exit = mlx_xpm_file_to_image(data->mlx, \
	"asset/exit.xpm", &width, &height);
	data->sprites.block = mlx_xpm_file_to_image(data->mlx, \
	"asset/block.xpm", &width, &height);
}

void	define_wall(t_data *data)
{
	int	width;
	int	height;

	data->sprites.wall_c_b_l = mlx_xpm_file_to_image(data->mlx, \
	"asset/wall_c_b_l.xpm", &width, &height);
	data->sprites.wall_c_b_r = mlx_xpm_file_to_image(data->mlx, \
	"asset/wall_c_b_r.xpm", &width, &height);
	data->sprites.wall_c_t_l = mlx_xpm_file_to_image(data->mlx, \
	"asset/wall_c_t_l.xpm", &width, &height);
	data->sprites.wall_c_t_r = mlx_xpm_file_to_image(data->mlx, \
	"asset/wall_c_t_r.xpm", &width, &height);
	data->sprites.wall_right = mlx_xpm_file_to_image(data->mlx, \
	"asset/wall_right.xpm", &width, &height);
	data->sprites.wall_left = mlx_xpm_file_to_image(data->mlx, \
	"asset/wall_left.xpm", &width, &height);
	data->sprites.wall_up = mlx_xpm_file_to_image(data->mlx, \
	"asset/wall_up.xpm", &width, &height);
	data->sprites.wall_down = mlx_xpm_file_to_image(data->mlx, \
	"asset/wall_down.xpm", &width, &height);
}
