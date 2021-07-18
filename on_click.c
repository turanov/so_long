#include "so_long.h"

int	ft_key_listener(int key, t_data *data)
{
	if (key == 53)
		return (free_data_and_quit(data));
	if (data->is_dead == 0)
	{
		data->random++;
		if (key == 13)
			ft_on_click_w(data);
		else if (key == 1)
			ft_on_click_s(data);
		else if (key == 0)
			ft_on_click_a(data);
		else if (key == 2)
			ft_on_click_d(data);
	}
	return (key);
}

int	ft_on_click_w(t_data *data)
{
	if (check_cop(data, -1, 0))
		return (1);
	else if (check_empty(data, -1, 0))
	{
	}
	else if (check_coin(data, -1, 0))
	{
	}
	else if (data->map[data->player_coor.i - 1][data->player_coor.j] == EXIT)
	{
		if (data->coins == data->goals)
			free_data_and_quit(data);
	}
	data->xpm_player = data->xpm_player_back;
	return (1);
}

int	ft_on_click_s(t_data *data)
{
	if (check_cop(data, 1, 0))
		return (1);
	else if (check_empty(data, 1, 0))
	{
	}
	else if (check_coin(data, 1, 0))
	{
	}
	else if (data->map[data->player_coor.i + 1][data->player_coor.j] == EXIT)
	{
		if (data->coins == data->goals)
			free_data_and_quit(data);
	}
	data->xpm_player = data->xpm_player_front;
	return (1);
}

int	ft_on_click_d(t_data *data)
{
	if (check_cop(data, 0, 1))
		return (1);
	else if (check_empty(data, 0, 1))
	{
	}
	else if (check_coin(data, 0, 1))
	{
	}
	else if (data->map[data->player_coor.i][data->player_coor.j + 1] == EXIT)
	{
		if (data->coins == data->goals)
			free_data_and_quit(data);
	}
	data->xpm_player = data->xpm_player_right;
	return (1);
}

int	ft_on_click_a(t_data *data)
{
	if (check_cop(data, 0, -1))
		return (1);
	else if (check_empty(data, 0, -1))
	{
	}
	else if (check_coin(data, 0, -1))
	{
	}
	else if (data->map[data->player_coor.i][data->player_coor.j - 1] == EXIT)
	{
		if (data->coins == data->goals)
			free_data_and_quit(data);
	}
	data->xpm_player = data->xpm_player_left;
	return (1);
}
