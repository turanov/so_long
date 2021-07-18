#include "so_long.h"

int	check_cop(t_data *data, int i, int j)
{
	if (data->map[data->player_coor.i + i][data->player_coor.j + j] == COP ||
		data->map[data->player_coor.i + i][data->player_coor.j + j]
		== COP_RIGHT ||
		data->map[data->player_coor.i + i][data->player_coor.j + j]
		== COP_LEFT ||
		data->map[data->player_coor.i + i][data->player_coor.j + j]
		== COP_FRONT ||
		data->map[data->player_coor.i + i][data->player_coor.j + j] == COP_BACK)
	{
		data->map[data->player_coor.i][data->player_coor.j] = EMPTY;
		data->player_coor.i += i;
		data->player_coor.j += j;
		data->map[data->player_coor.i][data->player_coor.j] = DEAD;
		data->moves++;
		data->is_dead = 1;
		data->xpm_player = data->xpm_player_dead;
		return (1);
	}
	return (0);
}

int	check_empty(t_data *data, int i, int j)
{
	if (data->map[data->player_coor.i + i][data->player_coor.j + j] == EMPTY)
	{
		data->map[data->player_coor.i][data->player_coor.j] = EMPTY;
		data->player_coor.i += i;
		data->player_coor.j += j;
		data->map[data->player_coor.i][data->player_coor.j] = PLAYER;
		data->moves++;
		return (1);
	}
	return (0);
}

int	check_coin(t_data *data, int i, int j)
{
	if (data->map[data->player_coor.i + i][data->player_coor.j + j] == COIN)
	{
		data->map[data->player_coor.i][data->player_coor.j] = EMPTY;
		data->player_coor.i += i;
		data->player_coor.j += j;
		data->map[data->player_coor.i][data->player_coor.j] = PLAYER;
		data->coins++;
		data->moves++;
		return (1);
	}
	return (0);
}
