#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 64
# define COIN 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define EMPTY '0'
# define WALL '1'
# define COP 'O'
# define DEAD	'D'
# define HEIGHT 100
# define SPEED_ANIMATION 15
# define SPEED_COP 40
# define COP_FRONT 'F'
# define COP_BACK 'B'
# define COP_LEFT 'L'
# define COP_RIGHT 'R'

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx_opengl_20191021/mlx.h"
# include <stdio.h>

typedef struct s_xpm
{
	int		i;
	int		j;
	void	*img;
}			t_xpm;

typedef struct s_coordinate
{
	int		i;
	int		j;
}			t_coordinate;

typedef struct s_data
{
	int				width;
	int				height;
	char			**map;

	void			*mlx_ptr;
	void			*win_ptr;

	int				coins;
	int				moves;
	int				goals;
	int				is_dead;

	unsigned int	change_coin;
	unsigned int	coin_mod_cnt;
	unsigned int	change_cop;
	unsigned int	random;

	t_xpm			xpm_coin;
	t_xpm			xpm_wall;
	t_xpm			xpm_empt;
	t_xpm			xpm_exit;
	t_xpm			xpm_black;
	t_xpm			xpm_door_closed;
	t_xpm			xpm_door_opened;
	t_xpm			xpm_player;
	t_xpm			xpm_player_dead;
	t_xpm			xpm_player_front;
	t_xpm			xpm_player_back;
	t_xpm			xpm_player_left;
	t_xpm			xpm_player_right;
	t_xpm			xpm_cop;
	t_xpm			xpm_cop_front;
	t_xpm			xpm_cop_back;
	t_xpm			xpm_cop_left;
	t_xpm			xpm_cop_right;
	t_coordinate	player_coor;
}					t_data;

void	ft_print_data(t_data *data);
void	read_file(char *filename, t_data *data);
void	ft_run(t_data *data);
void	ft_create_xmp_for_all(t_data *data);
void	ft_put_image(t_data *data, int i, int j);
int		free_data_and_quit(t_data *data);
int		ft_on_click_w(t_data *data);
int		ft_on_click_s(t_data *data);
int		ft_on_click_d(t_data *data);
int		ft_on_click_a(t_data *data);
void	ft_check_rectangular(char *filename, t_data *data);
void	ft_check_valid_values(t_data *data);
void	ft_check_surrounded_by_walls(t_data *data, int i, int j);
void	ft_check_has_exit(t_data *data, t_coordinate i_j, int player, int ex);
void	ft_check_file(char *filename, t_data *data);
void	ft_print_error(char *message, t_data *data);
void	free_arr(void **arr, int size);
void	ft_create_xpm(t_xpm *xmp, t_data *data, char *path);
int		free_data_and_quit(t_data *data);
void	free_arr(void **arr, int size);
void	fe_player_dead(t_data *data);
void	ft_cop_move(t_data *data, int i, int j);
int		check_cop(t_data *data, int i, int j);
int		check_empty(t_data *data, int i, int j);
int		check_coin(t_data *data, int i, int j);
int		ft_key_listener(int key, t_data *data);
void	ft_cop_update_direction_to_cop(t_data *data);
void	ft_cop_start(t_data *data);
void	ft_change_coin(t_data *data);
void	ft_put_to_window_moves_and_coins(t_data *data);
#endif
