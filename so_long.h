/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:12:02 by ljussiau          #+#    #+#             */
/*   Updated: 2023/12/13 11:32:37 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define ESC				53
# define W					13
# define A					0
# define S					1
# define D					2
# define DESTROY_NOTIFY		17

# define FRONT	"asset/player/front.xpm"
# define LEFT	"asset/player/left.xpm"
# define RIGHT	"asset/player/right.xpm"
# define BACK	"asset/player/back.xpm"

# define R_FRONT "asset/enemies/rocket_front.xpm"
# define R_BACK "asset/enemies/rocket_back.xpm"
# define R_LEFT "asset/enemies/rocket_left.xpm"
# define R_RIGHT "asset/enemies/rocket_right.xpm"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_map_bool
{
	bool	is_walled;
	bool	is_possible;
	int		nb_exit;
	int		nb_key;
	int		nb_start;
}		t_map_bool;

typedef struct s_player
{
	void	*frnt;
	void	*lft;
	void	*rght;
	void	*bck;
}		t_player;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*wall;
	void		*key;
	void		*floor;
	void		*exit;
	void		*ending;
	t_player	player;
	t_player	rocket;
	char		**area;
	int			nb_action;
	int			nb_key;
	char		last_case;
}		t_mlx_data;

void		flood_fill(char **tab, t_point size, t_point begin, t_map_bool *mp);
char		**create_area(char *path_map);
t_point		get_size(char **map);
t_point		get_begin(char **map, t_map_bool *map_bool);
int			check_begin(char **map, t_map_bool *map_bool);
t_map_bool	*init_map_bool(t_map_bool *map);
int			check_char(char **area);
int			map_validate(t_map_bool *map);
void		check_wall(char **map, t_point size, t_map_bool *map_bool);
char		*ft_strappend(char **s1, const char *s2);
char		**create_map(char *path);
int			handle_input(int key, t_mlx_data *data);
void		ft_print_line(char *str, t_mlx_data data, int y);
void		ft_find_player(char *str, t_mlx_data data, int y, char c);
void		ft_print_area(char **area, t_mlx_data data, char p, char r);
void		ft_print_player(char **area, t_mlx_data data, char c);
void		ft_print_map(char **tab);
void		go_up(t_mlx_data *data);
void		go_left(t_mlx_data *data);
void		go_right(t_mlx_data *data);
void		go_down(t_mlx_data *data);
t_point		get_pos(char **map, char c);
int			get_nb_key(char **map);
void		move_player(t_mlx_data *data, char c, int y, int x);
int			check_if_wall(t_mlx_data *data, char c, int y, int x);
int			close_game(t_mlx_data *data);
int			print_nb_move(t_mlx_data *data);
void		ft_print_rocket(char **area, t_mlx_data data, char c);
void		ft_find_rocket(char *str, t_mlx_data data, int y, char c);
char		move_rocket(t_mlx_data *data);
void		make_move(t_mlx_data *data, char c, int y, int x);
int			player_catched(char **area);
void		you_lose(t_mlx_data *data);
void		you_win(t_mlx_data *data);

#endif
