#include "so_long.h"

void	init_player_x_and_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == PLAYER)
			{
				data->player_coor.i = i;
				data->player_coor.j = j;
			}
			if (data->map[i][j] == COIN)
				data->goals++;
			j++;
		}
		i++;
	}
}

t_data	*create_data(void)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	data->width = 0;
	data->height = 0;
	data->coins = 0;
	data->moves = 0;
	data->goals = 0;
	data->is_dead = 0;
	data->change_coin = 1;
	data->coin_mod_cnt = 0;
	data->change_cop = 1;
	data->random = 0;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	data = create_data();
	read_file(argv[1], data);
	init_player_x_and_y(data);
	ft_run(data);
}
