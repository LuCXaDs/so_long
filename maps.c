/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:31:30 by luserbu           #+#    #+#             */
/*   Updated: 2022/06/15 18:46:07 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	dimension_maps(t_data *data)
{
	int fd;
	int i;
	char *str;

	i = 0;
	fd = open(data->name_maps, O_RDONLY);
	str = get_next_line(fd);
//	printf("%s first line\n\n", str);
	data->mapy = (int)ft_strlen(str) - 1;
//	printf("%d number of line\n\n", data->mapy);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		if (!str)
			break;
		i++;
	}
	free(str);
	data->mapx = i + 1;
//	printf("%d number of colum\n\ns", data->mapx);
	close(fd);
}

void	parsing(t_data *data)
{
	int	fd;
	int	y;
	int	i;
	
	y = 0;
	i = 0;
	fd = open(data->name_maps, O_RDONLY);
	data->maps = malloc(sizeof (char *) * data->mapy + 1);
	while (i < data->mapy)
	{
		data->maps[y] = get_next_line(fd);
		if (!data->maps[y])
			break;
		y++; 
		i++;
	}
	close(fd);
}

// void ft_print_map(t_data *data)
// {
// 	int y;

// 	y = 0;
// 	while (y < data->mapy)
// 	{
// 		ft_printf("%s", data->maps[y]);
// 		y++;
// 	}
// }

void	put_all_wall(t_data *data, int x, int y)
{
	if (x == 0 && (y > 0 && y != (data->mapy - 1)))
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.wall_up, 32*y, 32*x);
	else if (x > 0 && x < (data->mapx - 1) && y == (data->mapy - 1))
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.wall_right, 32*y, 32*x);
	else if (x == (data->mapx - 1) && (y > 0 && y != (data->mapy - 1)))
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.wall_down, 32*y, 32*x);
	else if ((x > 0 && x < (data->mapx - 1)) && y == 0)
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.wall_left, 32*y, 32*x);
	else
		put_corner_wall(data, x, y);
}

void	put_corner_wall(t_data *data, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.wall_c_t_l, 32*y, 32*x);
	else if (x == 0 && y == (data->mapy - 1))
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.wall_c_t_r, 32*y, 32*x);
 	else if (x == (data->mapx - 1) && y == 0)
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.wall_c_b_l, 32*y, 32*x);
 	else if (x == (data->mapx - 1) && y == (data->mapy - 1))
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.wall_c_b_r, 32*y, 32*x);
	else
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.block , 32*y, 32*x);
}
void	put_sprites(t_data *data, int x, int y)
{
	if (data->maps[x][y] == '0')
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.floor, 32*y, 32*x);
	else if  (data->maps[x][y] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.character, 32*y, 32*x);
		data->cha_pos_x = (int)x;
		data->cha_pos_y = (int)y;
	}
	else if (data->maps[x][y] == '1')
		put_all_wall(data, x, y);
	else if (data->maps[x][y] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.chest, 32*y, 32*x);
		data->coin += 1;
	}
	else if (data->maps[x][y] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.exit, 32*y, 32*x);
	else if (data->maps[x][y] == 'M')
		mlx_put_image_to_window(data->mlx, data->win,\
		data->sprites.ennemy, 32*y, 32*x);
}

void	put_sprites_into_maps(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->maps[x])
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

void	collect_and_close(t_data *data)
{
	int	x;
	int	y;
	int	coin;

	x = data->cha_pos_x;
	y = data->cha_pos_y;
	coin = data->coin;

	if (data->maps[x][y] == 'C')
	{
		data->maps[x][y] = '0';
		data->coin -= 1;
	}
	if (coin == 0)
		if (data->maps[data->cha_pos_x][data->cha_pos_y] == 'E')
			ft_close(data);
		
}


