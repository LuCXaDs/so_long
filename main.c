/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 22/05/26 11:21:35 by luserbu           #+#    #+#               */
/*   Updated: 22/06/15 18:08:39 by luserbu          ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_error(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] == 'r')
	{
		if (str[i - 2] == 'e')
			if (str[i - 3] == 'b')
				if (str[i - 4] == '.')
					if (str[i - 5] >= 33 && str[i - 5] <= 126)
						return (1);
	}
	return (0);
}
void	define_object(t_data *data)
{
	data->move = 0;
	data->coin = 0;
	data->ene_pos_x = 0;
	data->ene_pos_y = 0;
	data->P = 0;
    data->E = 0;
	data->number_wall_ext = 0;
	data->cpt_frame_ene = 0;

}
void	init_so_long(t_data *data)
{
	define_object(data);
	data->mlx = mlx_init();
	dimension_maps(data);
	parsing(data);
	error_maps(data);
//	ft_print_map(data);
	define_wall(data);
	define_other_sprites(data);
	define_frame_character(data);
	define_frame_ennemy(data);
	data->win = mlx_new_window(data->mlx, data->mapy * 32,\
	data->mapx * 32, "CHINTCHANTCHOMG MIAOU");
	put_sprites_into_maps(data);
	mlx_string_put(data->mlx, data->win, 40, 25, 0xffffff, "MOVE");
	mlx_key_hook(data->win, define_move_character, data);
	mlx_loop_hook(data->mlx, frames, data);
	mlx_hook(data->win, 17, 2L << 0, ft_close, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_data	data;
		data.name_maps = av[1];
		if (file_error(data.name_maps) == 1)
			init_so_long(&data);
		else
			return (ft_printf("Error\n/* file error name */\n"),\
			ft_close(&data));
	}
	else
		ft_printf("/* incorrect argument */\n");
	return (0);
}
