#include "so_long.h"

void	define_frame_character(t_data *data)
{
	int width;
	int	height;

	data->frame_char[0] = mlx_xpm_file_to_image(data->mlx,\
	"frames/char_fra00.xpm", &width, &height);
	data->frame_char[1] = mlx_xpm_file_to_image(data->mlx,\
	"frames/char_fra01.xpm", &width, &height);
	data->frame_char[2] = mlx_xpm_file_to_image(data->mlx,\
	"frames/char_fra02.xpm", &width, &height);
	data->frame_char[3] = mlx_xpm_file_to_image(data->mlx,\
	"frames/char_fra03.xpm", &width, &height);
	data->frame_char[4] = mlx_xpm_file_to_image(data->mlx,\
	"frames/char_fra04.xpm", &width, &height);
	data->frame_char[5] = mlx_xpm_file_to_image(data->mlx,\
	"frames/char_fra05.xpm", &width, &height);
	data->frame_char[6] = mlx_xpm_file_to_image(data->mlx,\
	"frames/char_fra06.xpm", &width, &height);
	data->frame_char[7] = mlx_xpm_file_to_image(data->mlx,\
	"frames/char_fra07.xpm", &width, &height);
	data->frame_char[8] = mlx_xpm_file_to_image(data->mlx,\
	"frames/char_fra08.xpm", &width, &height);
	data->frame_char[9] = mlx_xpm_file_to_image(data->mlx,\
	"frames/char_fra09.xpm", &width, &height);
}

void	define_frame_ennemy(t_data *data)
{
	int width;
	int	height;

	data->frame_ene[0] = mlx_xpm_file_to_image(data->mlx,\
	"frames/ene_fra00.xpm", &width, &height);
	data->frame_ene[1] = mlx_xpm_file_to_image(data->mlx,\
	"frames/ene_fra01.xpm", &width, &height);
	data->frame_ene[2] = mlx_xpm_file_to_image(data->mlx,\
	"frames/ene_fra02.xpm", &width, &height);
	data->frame_ene[3] = mlx_xpm_file_to_image(data->mlx,\
	"frames/ene_fra03.xpm", &width, &height);
	data->frame_ene[4] = mlx_xpm_file_to_image(data->mlx,\
	"frames/ene_fra04.xpm", &width, &height);
}

void	define_other_sprites(t_data *data)
{
	int width;
	int	height;

	data->sprites.floor = mlx_xpm_file_to_image(data->mlx,\
	"asset/floor01.xpm", &width, &height);
	data->sprites.character = mlx_xpm_file_to_image(data->mlx,\
	"asset/character01.xpm", &width, &height);
	data->sprites.chest = mlx_xpm_file_to_image(data->mlx,\
	"asset/chest.xpm", &width, &height);
	data->sprites.exit = mlx_xpm_file_to_image(data->mlx,\
	"asset/exit.xpm", &width, &height);
	data->sprites.block = mlx_xpm_file_to_image(data->mlx,\
	"asset/block.xpm", &width, &height);
	data->sprites.ennemy = mlx_xpm_file_to_image(data->mlx,\
	"asset/ennemy.xpm", &width, &height);
	data->sprites.wall_up_move00 = mlx_xpm_file_to_image(data->mlx,\
	"asset/wall_up_move00.xpm", &width, &height);
	data->sprites.wall_up_move01 = mlx_xpm_file_to_image(data->mlx,\
	"asset/wall_up_move01.xpm", &width, &height);
}

void	define_wall(t_data *data)
{
	int width;
	int	height;

	data->sprites.wall_c_b_l = mlx_xpm_file_to_image(data->mlx,\
	"asset/wall_c_b_l.xpm", &width, &height);
	data->sprites.wall_c_b_r = mlx_xpm_file_to_image(data->mlx,\
	"asset/wall_c_b_r.xpm", &width, &height);
	data->sprites.wall_c_t_l = mlx_xpm_file_to_image(data->mlx,\
	"asset/wall_c_t_l.xpm", &width, &height);
	data->sprites.wall_c_t_r = mlx_xpm_file_to_image(data->mlx,\
	"asset/wall_c_t_r.xpm", &width, &height);
	data->sprites.wall_right = mlx_xpm_file_to_image(data->mlx,\
	"asset/wall_right.xpm", &width, &height);
	data->sprites.wall_left = mlx_xpm_file_to_image(data->mlx,\
	"asset/wall_left.xpm", &width, &height);
	data->sprites.wall_up = mlx_xpm_file_to_image(data->mlx,\
	"asset/wall_up.xpm", &width, &height);
	data->sprites.wall_down = mlx_xpm_file_to_image(data->mlx,\
	"asset/wall_down.xpm", &width, &height);
}