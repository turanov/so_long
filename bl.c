#include "so_long.h"

void	ft_check_is_dead(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == DEAD && data->is_dead == 0)
			{
				data->is_dead = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	if (data->is_dead >= 100)
		free_data_and_quit(data);
	if (data->is_dead != 0)
		data->is_dead++;
}

int	ft_display(t_data *data)
{
	int	i;
	int	j;

	ft_cop_start(data);
	i = 0;
	if (data->coins == data->goals)
		data->xpm_exit = data->xpm_door_opened;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			ft_put_image(data, j, i);
			data->random++;
			j++;
		}
		i++;
	}
	ft_check_is_dead(data);
	data->change_cop++;
	data->random++;
	ft_put_to_window_moves_and_coins(data);
	ft_change_coin(data);
	return (1);
}

void	ft_run(t_data *data)
{
	data->mlx_ptr = mlx_init();
	ft_create_xmp_for_all(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * PIXEL,
			data->height * PIXEL + HEIGHT, "SO LONG");
	mlx_hook(data->win_ptr, 2, 1L << 0, ft_key_listener, data);
	mlx_hook(data->win_ptr, 17, 1L << 5, free_data_and_quit, data);
	mlx_loop_hook(data->mlx_ptr, ft_display, data);
	mlx_loop(data->mlx_ptr);
}
