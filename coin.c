#include "so_long.h"

void	ft_put_to_window_moves_and_coins(t_data *data)
{
	char	*moves_str;
	char	*moves_cnt;
	char	*coins_str;
	char	*coins_cnt;

	moves_str = ft_strdup("MOVES: ");
	moves_cnt = ft_itoa(data->moves);
	coins_str = ft_strdup("COINS: ");
	coins_cnt = ft_itoa(data->coins);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->xpm_black.img, 50, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 10, 0xFF99FF, moves_str);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 10, 0xCCCCCC, moves_cnt);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 30, 0xFF99FF, coins_str);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 30, 0xCCCCCC, coins_cnt);
	free(moves_str);
	free(moves_cnt);
	free(coins_str);
	free(coins_cnt);
}

char	*ft_get_coin_path(t_data *data, char num)
{
	char	*gold;
	char	*number;
	char	*xpm;

	gold = ft_strdup("./xpm/gold_");
	number = (char *) malloc(2);
	if (!number)
		free_data_and_quit(data);
	xpm = ft_strdup(".xpm");
	if (!xpm)
	{
		free(number);
		free_data_and_quit(data);
	}
	number[0] = num;
	number[1] = 0;
	gold = ft_strjoin(gold, number);
	gold = ft_strjoin(gold, xpm);
	return (gold);
}

void	ft_change_coin(t_data *data)
{
	char	*str;

	if (data->change_coin % SPEED_ANIMATION == 0)
	{
		str = ft_get_coin_path(data, data->coin_mod_cnt % 10 + 48);
		ft_create_xpm(&data->xpm_coin, data, str);
		data->coin_mod_cnt++;
		if (data->coin_mod_cnt == 10)
			data->coin_mod_cnt = 0;
		data->change_coin = 1;
		free(str);
		data->random++;
	}
	else
		data->change_coin++;
}
