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

#include "so_long.h"

int    verif_ext_wall(t_data *data, int x, int y)
{
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

void    loop_error_maps(t_data *data, int x, int y)
{
    if (data->maps[x][y] == 'P')
    {
        data->P += 1;
        if (data->P == 2)
        {
            data->maps[x][y] = '0';
            ft_printf("Impossible to play with many PLAYER */\n ");  
        }
        else if (data->P > 2)
            data->maps[x][y] = '0';
    }
    else if (data->maps[x][y] == 'E')
    {
        data->E += 1;
        if (data->E == 2)
        {
            data->maps[x][y] = '0';
            ft_printf("Impossible to play with many EXIT */\n ");  
        }
        else if (data->E > 2)
            data->maps[x][y] = '0';
    }
    else if (data->maps[x][y] == '1')
        verif_ext_wall(data, x, y);
}

void	verif_letter(t_data *data, char c)
{
	if (c == '1' || c == '0' || c == 'C'
		|| c == 'E' || c == 'P' || c == 'M' || c == '\n')
		return ;
	else
    {
		ft_printf("Error\n/* Wrong argument ! */\n ");
        ft_exit_error(data);
    }
}

int    error_maps(t_data *data)
{
    int	x;
	int	y;
    int verif_y;
    int verif_coin;

	x = 0;
    verif_coin = 0;
	y = (int)data->mapy;
    verif_y = (int)data->mapy;
    while (data->maps[x])
	{
        if (y == verif_y)
        {
            y = 0;
            while (data->maps[x][y])
            {
                loop_error_maps(data, x, y);
                verif_letter(data, data->maps[x][y]);
                if (data->maps[x][y] == 'C')
                    verif_coin++;
                y++;
            }
            y--;
        }
        else
            return (ft_printf("Error\n/* Incorrect map size */\n "),\
            ft_exit_error(data));
		x++;
	}
    if (verif_coin == 0)
        return (ft_printf("Error\n/* Incorrect number of collectibles */\n "),\
        ft_exit_error(data));
    if ((data->mapx + data->mapy - 2) * 2 != verif_ext_wall(data, x, y))
    {
        //ft_printf("Error\n/* Incorrect placement of walls */\n\n");
        error_message(data, "Incorrect placement of walls");
        return (ft_exit_error(data));
    }
    return (0);
}