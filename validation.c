#include "so_long.h"

void	ft_check_rectangular(char *filename, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		if (data->width != (int) ft_strlen(line))
		{
			ft_print_error("THE MAP IS NOT RECTANGLE!\n", data);
			free(line);
			exit(1);
		}
		free(line);
	}
	free(line);
	close(fd);
}

void	ft_check_valid_values(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] != EXIT && data->map[i][j] != EMPTY
				&& data->map[i][j] != PLAYER && data->map[i][j] != COIN
				&& data->map[i][j] != WALL && data->map[i][j] != COP)
			{
				free_arr((void **) data->map, data->height);
				ft_print_error("GAVE INVALID VALUES\n", data);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_surrounded_by_walls(t_data *data, int i, int j)
{
	while (i < data->height)
	{
		if (data->map[i][0] != WALL || data->map[i][data->width - 1] != WALL)
		{
			free_arr((void **) data->map, data->height);
			ft_print_error("THE MAP MUST BE SURROUNDED WITH WALLS\n", data);
			exit(1);
		}
		i++;
	}
	while (j < data->width)
	{
		if (data->map[0][j] != WALL || data->map[data->height - 1][j] != WALL)
		{
			free_arr((void **) data->map, data->height);
			ft_print_error("THE MAP MUST BE SURROUNDED WITH WALLS\n", data);
			exit(1);
		}
		j++;
	}
}

void	ft_check_has_exit(t_data *data, t_coordinate i_j, int player, int ex)
{
	int	coin;

	coin = 0;
	while (i_j.i < data->height)
	{
		i_j.j = 0;
		while (i_j.j < data->width)
		{
			if (data->map[i_j.i][i_j.j] == EXIT)
				ex++;
			if (data->map[i_j.i][i_j.j] == PLAYER)
				player++;
			if (data->map[i_j.i][i_j.j] == COIN)
				coin++;
			i_j.j++;
		}
		i_j.i++;
	}
	if (!(player == 1 && coin != 0 && ex != 0))
	{
		free_arr((void **) data->map, data->height);
		ft_print_error("THE MAP MUST HAVE AT LEAST ONE EXIT\n", data);
		exit(1);
	}
}

void	ft_check_file(char *filename, t_data *data)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_print_error("FILE NOT FOUND!\n", data);
		exit(1);
	}
	close(fd);
}
