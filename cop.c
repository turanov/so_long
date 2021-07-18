#include "so_long.h"

void	ft_cop_direction(t_data *data, t_coordinate x_y,
			t_coordinate i_j, char direction)
{
	if (data->map[x_y.i + i_j.i][x_y.j + i_j.j] == EMPTY)
	{
		data->random += (i_j.i + i_j.j);
		data->map[x_y.i][x_y.j] = EMPTY;
		data->map[x_y.i + i_j.i][x_y.j + i_j.j] = direction;
		data->random++;
	}
	else if (data->map[x_y.i + i_j.i][x_y.j + i_j.j] == PLAYER)
	{
		data->map[x_y.i][x_y.j] = EMPTY;
		data->map[x_y.i + i_j.i][x_y.j + i_j.j] = DEAD;
		data->xpm_player = data->xpm_player_dead;
	}
}

void	ft_cop_choose_direction(t_data *data, t_coordinate x_y,
		t_coordinate i_j, int mod)
{
	if (mod == 0)
	{
		i_j.i = 1;
		i_j.j = 0;
		ft_cop_direction(data, x_y, i_j, COP_FRONT);
	}
	else if (mod == 1)
	{
		i_j.i = -1;
		i_j.j = 0;
		ft_cop_direction(data, x_y, i_j, COP_BACK);
	}
	else if (mod == 2)
	{
		i_j.i = 0;
		i_j.j = 1;
		ft_cop_direction(data, x_y, i_j, COP_RIGHT);
	}
	else
		ft_cop_direction(data, x_y, i_j, COP_LEFT);
}

void	ft_cop_move(t_data *data, int i, int j)
{
	t_coordinate	x_y;
	t_coordinate	i_j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == COP)
			{
				x_y.i = i;
				x_y.j = j;
				i_j.i = 0;
				i_j.j = -1;
				ft_cop_choose_direction(data, x_y, i_j,
					(data->random + j * j + i) % 4);
				data->random += 2;
			}
			j++;
		}
		i++;
	}
}

void	ft_cop_update_direction_to_cop(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == COP_RIGHT || data->map[i][j] == COP_LEFT ||
				data->map[i][j] == COP_FRONT ||
				data->map[i][j] == COP_BACK)
				data->map[i][j] = COP;
			j++;
		}
		i++;
	}
}

void	ft_cop_start(t_data *data)
{
	if (data->change_cop % SPEED_COP == 0)
	{
		data->change_cop = 1;
		ft_cop_update_direction_to_cop(data);
		ft_cop_move(data, 0, 0);
		data->random++;
	}
}
