#include "so_long.h"

void	ft_create_xpm(t_xpm *xmp, t_data *data, char *path)
{
	xmp->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &xmp->j, &xmp->i);
	if (!xmp->img)
	{
		perror("CAN\'T LOAD XPM|");
		exit(1);
	}
}

void	ft_create_xmp_for_all(t_data *data)
{
	ft_create_xpm(&data->xpm_player_front, data, "./xpm/player_front.xpm");
	ft_create_xpm(&data->xpm_player_back, data, "./xpm/player_back.xpm");
	ft_create_xpm(&data->xpm_player_right, data, "./xpm/player_right.xpm");
	ft_create_xpm(&data->xpm_player_left, data, "./xpm/player_left.xpm");
	ft_create_xpm(&data->xpm_player_dead, data, "./xpm/player_dead.xpm");
	ft_create_xpm(&data->xpm_wall, data, "./xpm/wall.xpm");
	ft_create_xpm(&data->xpm_coin, data, "./xpm/coin.xpm");
	ft_create_xpm(&data->xpm_empt, data, "./xpm/empty.xpm");
	ft_create_xpm(&data->xpm_exit, data, "./xpm/door_opened.xpm");
	ft_create_xpm(&data->xpm_black, data, "./xpm/black.xpm");
	ft_create_xpm(&data->xpm_door_opened, data, "./xpm/door_opened.xpm");
	ft_create_xpm(&data->xpm_door_closed, data, "./xpm/door_closed.xpm");
	ft_create_xpm(&data->xpm_cop_front, data, "./xpm/cop_front.xpm");
	ft_create_xpm(&data->xpm_cop_back, data, "./xpm/cop_back.xpm");
	ft_create_xpm(&data->xpm_cop_left, data, "./xpm/cop_left.xpm");
	ft_create_xpm(&data->xpm_cop_right, data, "./xpm/cop_right.xpm");
	data->xpm_cop = data->xpm_cop_front;
	data->xpm_exit = data->xpm_door_closed;
	data->xpm_player = data->xpm_player_front;
}

void	ft_put_image_helper(t_data *data, int x, int y)
{
	if (data->map[y][x] == COP_FRONT)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->xpm_cop_front.img, x * PIXEL,
			y * PIXEL + HEIGHT);
	else if (data->map[y][x] == COP_BACK)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->xpm_cop_back.img, x * PIXEL,
			y * PIXEL + HEIGHT);
	else if (data->map[y][x] == COP_LEFT)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->xpm_cop_left.img, x * PIXEL,
			y * PIXEL + HEIGHT);
	else if (data->map[y][x] == COP_RIGHT)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->xpm_cop_right.img, x * PIXEL,
			y * PIXEL + HEIGHT);
	else if (data->map[y][x] == COP)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->xpm_cop.img, x * PIXEL, y * PIXEL + HEIGHT);
	else if (data->map[y][x] == PLAYER || data->map[y][x] == DEAD)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->xpm_player.img, x * PIXEL, y * PIXEL + HEIGHT);
}

void	ft_put_image(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->xpm_empt.img, x * PIXEL, y * PIXEL + HEIGHT);
	if (data->map[y][x] == WALL)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->xpm_wall.img, x * PIXEL, y * PIXEL + HEIGHT);
	else if (data->map[y][x] == EXIT)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->xpm_exit.img, x * PIXEL, y * PIXEL + HEIGHT);
	else if (data->map[y][x] == COIN)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->xpm_coin.img, x * PIXEL, y * PIXEL + HEIGHT);
	else
		ft_put_image_helper(data, x, y);
}
