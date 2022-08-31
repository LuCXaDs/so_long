/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:31:30 by luserbu           #+#    #+#             */
/*   Updated: 2022/06/15 18:46:07 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_all_wall(t_data *data, int x, int y)
{
	if (x == 0 && (y > 0 && y != (data->mapy - 1)))
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.wall_up, 32
			* y, 32 * x);
	else if (x > 0 && x < (data->mapx - 1) && y == (data->mapy - 1))
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.wall_right,
			32 * y, 32 * x);
	else if (x == (data->mapx - 1) && (y > 0 && y != (data->mapy - 1)))
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.wall_down,
			32 * y, 32 * x);
	else if ((x > 0 && x < (data->mapx - 1)) && y == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.wall_left,
			32 * y, 32 * x);
	else
		put_corner_wall(data, x, y);
}

void	put_corner_wall(t_data *data, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.wall_c_t_l,
			32 * y, 32 * x);
	else if (x == 0 && y == (data->mapy - 1))
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.wall_c_t_r,
			32 * y, 32 * x);
	else if (x == (data->mapx - 1) && y == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.wall_c_b_l,
			32 * y, 32 * x);
	else if (x == (data->mapx - 1) && y == (data->mapy - 1))
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.wall_c_b_r,
			32 * y, 32 * x);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.block, 32
			* y, 32 * x);
}

void	put_sprites(t_data *data, int x, int y)
{
	if (data->maps[x][y] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.floor, 32
			* y, 32 * x);
	else if (data->maps[x][y] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.character,
			32 * y, 32 * x);
		data->cha_pos_x = (int)x;
		data->cha_pos_y = (int)y;
	}
	else if (data->maps[x][y] == '1')
		put_all_wall(data, x, y);
	else if (data->maps[x][y] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.chest, 32
			* y, 32 * x);
		data->coin += 1;
	}
	else if (data->maps[x][y] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.exit, 32
			* y, 32 * x);
}

void	put_sprites_into_maps(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->mapx)
	{
		y = 0;
		while (data->maps[x][y])
		{
			put_sprites(data, x, y);
			y++;
		}
		x++;
	}
}
