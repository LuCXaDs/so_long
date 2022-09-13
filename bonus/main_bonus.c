/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:21:35 by serbu             #+#    #+#             */
/*   Updated: 2022/09/04 19:59:02 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	empty_file(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->name_maps, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (free(line), 1);
	}
	close(fd);
	return (free(line), 0);
}

int	file_error(char *str, t_data *data)
{
	int		fd;
	int		i;

	fd = open(str, O_RDONLY);
	if (fd < 0 || empty_file(data) == 1)
		return (0);
	i = ft_strlen(str);
	if (str[i - 5] > 32 && str[i - 5] < 127)
		if (str[i - 1] == 'r')
			if (str[i - 2] == 'e')
				if (str[i - 3] == 'b')
					if (str[i - 4] == '.')
						return (1);
	return (0);
}

void	define_object(t_data *data, t_path *path)
{
	data->move = 0;
	data->coin = 0;
	data->ene_pos_x = 0;
	data->ene_pos_y = 0;
	data->verif_coin = 0;
	data->play = 0;
	data->ext = 0;
	data->number_wall_ext = 0;
	data->cpt_frame_ene = 0;
	data->mapx = 1;
	data->mapy = 0;
	path->nb_floor = 0;
	path->nb_ext = 0;
	path->nb_coin = 0;
	path->roll_back = 0;
}

void	init_so_long(t_data *data, t_path *path)
{
	define_object(data, path);
	data->mlx = mlx_init();
	dimension_maps(data);
	parsing(data);
	error_maps_size(data);
	error_maps(data);
	check_path(data, path);
	exit_path(data, path, 1);
	define_wall(data);
	define_other_sprites(data);
	define_frame_character(data);
	define_frame_ennemy(data);
	data->win = mlx_new_window(data->mlx, data->mapy * 32, \
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
	t_data	data;
	t_path	path;

	if (ac == 2)
	{
		data.name_maps = av[1];
		if (file_error(data.name_maps, &data) == 1)
			init_so_long(&data, &path);
		else
			ft_printf("Error\n/* file error name */\n");
	}
	else
		ft_printf("Error\n/* incorrect argument */\n");
	return (0);
}
