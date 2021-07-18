#include "so_long.h"

int	get_height(char *filename)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(filename, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(filename, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_strlen(line);
	free(line);
	close(fd);
	return (width);
}

void	ft_print_error(char *message, t_data *data)
{
	ft_putstr_fd(message, 1);
	free(data);
}

void	check_map(t_data *data)
{
	t_coordinate	i_j;

	i_j.i = 0;
	i_j.j = 0;
	ft_check_valid_values(data);
	ft_check_surrounded_by_walls(data, 0, 0);
	ft_check_has_exit(data, i_j, 0, 0);
}

void	read_file(char *filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	ft_check_file(filename, data);
	data->height = get_height(filename);
	data->width = get_width(filename);
	ft_check_rectangular(filename, data);
	data->map = (char **) malloc(sizeof(char *) * (data->height + 1));
	fd = open(filename, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		data->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	data->map[i] = NULL;
	check_map(data);
}
