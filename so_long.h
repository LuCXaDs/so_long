/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:32:31 by luserbu           #+#    #+#             */
/*   Updated: 2022/08/23 17:03:38 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_linux/mlx.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <time.h>

# define IMG_SIZE 32

typedef struct s_sprites
{
	void		*character;
	void		*floor;
	void		*wall_left;
	void		*wall_right;
	void		*wall_down;
	void		*wall_up;
	void		*wall_c_t_l;
	void		*wall_c_t_r;
	void		*wall_c_b_l;
	void		*wall_c_b_r;
	void		*chest;
	void		*exit;
	void		*block;
}				t_sprites;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*name_maps;
	int			number_wall_ext;
	int			ext;
	int			play;
	int			mapx;
	int			mapy;
	int			verif_coin;
	int			cha_pos_x;
	int			cha_pos_y;
	int			ene_pos_x;
	int			ene_pos_y;
	int			coin;
	int			move;
	char		**maps;
	t_sprites	sprites;
}				t_data;

void			dimension_maps(t_data *data);
void			parsing(t_data *data);
void			ft_print_map(t_data *data);
void			define_other_sprites(t_data *data);
void			define_wall(t_data *data);
int				define_move_character(int keycode, t_data *data);
void			put_sprites_into_maps(t_data *data);
void			put_corner_wall(t_data *data, int x, int y);
void			put_all_wall(t_data *data, int x, int y);
void			collect_and_close(t_data *data);
int				ft_close(t_data *data);
void			ft_error(t_data *data);
void			error_maps(t_data *data);
int				ft_exit_error(t_data *data);
void			print_error(t_data *data, int error, int x, int y);
void			error_maps_size(t_data *data);
// int		error_maps_size(t_data *data);
void			pute(t_data *data);
#endif
