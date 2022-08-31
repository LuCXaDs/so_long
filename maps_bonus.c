/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:31:30 by luserbu           #+#    #+#             */
/*   Updated: 2022/07/25 16:55:30 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	dimension_maps(t_data *data)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(data->name_maps, O_RDONLY);
	str = get_next_line(fd);
	data->mapy = (int)ft_strlen(str) - 1;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		if (!str)
			break ;
		i++;
	}
	free(str);
	data->mapx = i + 1;
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
	data->maps = ft_calloc(sizeof (char *), (size_t)data->mapy + 1);
	while (i < data->mapx)
	{
		data->maps[y] = get_next_line(fd);
		y++;
		i++;
	}
	close(fd);
}

void	error_maps_size(t_data *data)
{
	int	len;

	if (!data->maps[0])
		print_error(data, 4, 0, 0);
	len = (int)ft_strlen(data->maps[0]);
	if ((int)ft_strlen(data->maps[data->mapx - 1]) != len)
		print_error(data, 4, 0, 0);
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
			win_or_lose(data, 1);
}
