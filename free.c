#include "so_long.h"

void	free_arr(void **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}

int	free_data_and_quit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	free(data->xpm_cop_front.img);
	free(data->xpm_cop_back.img);
	free(data->xpm_cop_left.img);
	free(data->xpm_cop_right.img);
	free(data->xpm_coin.img);
	free(data->xpm_wall.img);
	free(data->xpm_empt.img);
	free(data->xpm_black.img);
	free(data->xpm_door_opened.img);
	free(data->xpm_door_closed.img);
	free(data->xpm_player_front.img);
	free(data->xpm_player_back.img);
	free(data->xpm_player_right.img);
	free(data->xpm_player_left.img);
	while (data->height--)
		free(data->map[data->height]);
	free(data->map);
	free(data);
	exit(1);
}
