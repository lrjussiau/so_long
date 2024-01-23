/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:51:24 by ljussiau          #+#    #+#             */
/*   Updated: 2023/12/14 07:59:51 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_mlx_data *data)
{
	if (key == ESC)
	{
		ft_putstr_fd("You Quit the game ! Bye", 1);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (key == W)
		go_up(data);
	else if (key == S)
		go_down(data);
	else if (key == D)
		go_right(data);
	else if (key == A)
		go_left(data);
	return (0);
}

void	go_up(t_mlx_data *data)
{
	t_point	pos;
	char	c;

	pos = get_pos(data->area, 'P');
	c = '\0';
	if (check_if_wall(data, 'w', pos.y, pos.x) == 0)
	{
		data->nb_action++;
		move_player(data, 'w', pos.y, pos.x);
		ft_putstr_fd("Move : ", 1);
		ft_putnbr_fd(data->nb_action, 1);
		write(1, "\n", 1);
		if (get_nb_key(data -> area) == 0 && data -> last_case == 'E')
			you_win(data);
	}
	ft_print_area(data->area, *data, 'w', c);
	c = move_rocket(data);
	ft_print_area(data->area, *data, 'w', c);
	if (player_catched(data -> area) == 0)
		you_lose(data);
}

void	go_down(t_mlx_data *data)
{
	t_point	pos;
	char	c;

	pos = get_pos(data->area, 'P');
	c = '\0';
	if (check_if_wall(data, 's', pos.y, pos.x) == 0)
	{
		data->nb_action++;
		move_player(data, 's', pos.y, pos.x);
		ft_putstr_fd("Move : ", 1);
		ft_putnbr_fd(data->nb_action, 1);
		write(1, "\n", 1);
		if (get_nb_key(data -> area) == 0 && data -> last_case == 'E')
			you_win(data);
	}
	ft_print_area(data->area, *data, 'w', c);
	c = move_rocket(data);
	ft_print_area(data->area, *data, 's', c);
	if (player_catched(data -> area) == 0)
		you_lose(data);
}

void	go_left(t_mlx_data *data)
{
	t_point	pos;
	char	c;

	pos = get_pos(data->area, 'P');
	c = '\0';
	if (check_if_wall(data, 'a', pos.y, pos.x) == 0)
	{
		data->nb_action++;
		move_player(data, 'a', pos.y, pos.x);
		ft_putstr_fd("Move : ", 1);
		ft_putnbr_fd(data->nb_action, 1);
		write(1, "\n", 1);
		if (get_nb_key(data -> area) == 0 && data -> last_case == 'E')
			you_win(data);
	}
	ft_print_area(data->area, *data, 'w', c);
	c = move_rocket(data);
	ft_print_area(data->area, *data, 'a', c);
	if (player_catched(data -> area) == 0)
		you_lose(data);
}

void	go_right(t_mlx_data *data)
{
	t_point	pos;
	char	c;

	pos = get_pos(data->area, 'P');
	c = '\0';
	if (check_if_wall(data, 'd', pos.y, pos.x) == 0)
	{
		data->nb_action++;
		move_player(data, 'd', pos.y, pos.x);
		ft_putstr_fd("Move : ", 1);
		ft_putnbr_fd(data->nb_action, 1);
		write(1, "\n", 1);
		if (get_nb_key(data -> area) == 0 && data -> last_case == 'E')
			you_win(data);
	}
	ft_print_area(data->area, *data, 'w', c);
	c = move_rocket(data);
	ft_print_area(data->area, *data, 'd', c);
	if (player_catched(data -> area) == 0)
		you_lose(data);
}
