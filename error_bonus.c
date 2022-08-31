/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:01:15 by luserbu           #+#    #+#             */
/*   Updated: 2022/06/22 17:01:15 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	verif_ext_wall(t_data *data, int x, int y)
{
	y = y;
	if (x == 0 && (y >= 0 && y != data->mapy))
		data->number_wall_ext += 1;
	if (x == (data->mapx - 1) && (y >= 0 && y != data->mapy))
		data->number_wall_ext += 1;
	if ((x > 0 && x < (data->mapx - 1)) && y == 0)
		data->number_wall_ext += 1;
	if ((x > 0 && x < (data->mapx - 1)) && y == data->mapy - 1)
		data->number_wall_ext += 1;
	return (data->number_wall_ext);
}

void	loop_error_maps(t_data *data, int x, int y)
{
	if (data->maps[x][y] == 'P')
		data->play += 1;
	else if (data->maps[x][y] == 'E')
		data->ext += 1;
	else if (data->maps[x][y] == '1')
		verif_ext_wall(data, x, y);
}

void	print_error(t_data *data, int error, int x, int y)
{
	if (error == 0 && data->verif_coin == 0)
		ft_printf("Error\n/* Incorrect number of collectibles */\n");
	if (error == 0 && (data->mapx + data->mapy - 2) * 2 \
	!= verif_ext_wall(data, x, y))
		ft_printf("Error\n/* Incorrect placement of walls */\n");
	if (error == 1 || data->play == 0 || data->play >= 2)
		ft_printf("Error\n/* Impossible to play with many or none PLAYER */\n");
	if (error == 2 || data->ext == 0 || data->ext >= 2)
		ft_printf("Error\n/* Impossible to play with many or none EXIT */\n");
	if (error == 3)
		ft_printf("Error\n/* Wrong argument ! */\n");
	if (error == 4)
		ft_printf("Error\n/* Incorrect map size */\n");
	if ((error == 0 && data->verif_coin == 0) || (error == 0 \
	&& (data->mapx + data->mapy - 2) * 2 != verif_ext_wall(data, x, y)) \
	|| error == 1 || data->play == 0 || data->play >= 2 || error == 2 \
	|| data->ext == 0 || data->ext >= 2 || error == 3 || error == 4)
		ft_exit_error(data);
}

void	verif_letter_line(t_data *data, char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'M'
		|| c == '\n')
		return ;
	else
		print_error(data, 3, 0, 0);
}

void	error_maps(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = data->mapy + 1;
	while (x < data->mapx)
	{
		if ((y - 1) == data->mapy)
		{
			y = 0;
			while (data->maps[x][y])
			{
				loop_error_maps(data, x, y);
				verif_letter_line(data, data->maps[x][y]);
				if (data->maps[x][y] == 'C')
					data->verif_coin++;
				y++;
			}
		}
		else
			print_error(data, 4, 0, 0);
		x++;
	}
	print_error(data, 0, x, y);
}
