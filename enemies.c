/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:00:40 by ljussiau          #+#    #+#             */
/*   Updated: 2023/12/13 11:31:59 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_rocket(char **area, t_mlx_data data, char c)
{
	int	y;
	int	i;

	data.rocket.frnt = mlx_xpm_file_to_image(data.mlx, R_FRONT, &y, &i);
	data.rocket.bck = mlx_xpm_file_to_image(data.mlx, R_BACK, &y, &i);
	data.rocket.lft = mlx_xpm_file_to_image(data.mlx, R_LEFT, &y, &i);
	data.rocket.rght = mlx_xpm_file_to_image(data.mlx, R_RIGHT, &y, &i);
	data.floor = mlx_xpm_file_to_image(data.mlx, "asset/floor.xpm", &y, &i);
	y = 0;
	i = 0;
	while (area[i] != NULL)
	{
		ft_find_rocket(area[i], data, y, c);
		i++;
		y += 64;
	}
	return ;
}

void	ft_find_rocket(char *str, t_mlx_data data, int y, char c)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'X' && c == 's')
			mlx_put_image_to_window(data.mlx, data.win, data.rocket.frnt, x, y);
		if (str[i] == 'X' && c == 'w')
			mlx_put_image_to_window(data.mlx, data.win, data.rocket.bck, x, y);
		if (str[i] == 'X' && c == 'a')
			mlx_put_image_to_window(data.mlx, data.win, data.rocket.lft, x, y);
		if (str[i] == 'X' && c == 'd')
			mlx_put_image_to_window(data.mlx, data.win, data.rocket.rght, x, y);
		if (str[i] == 'X' && c == 'b')
		{
			mlx_put_image_to_window(data.mlx, data.win, data.floor, x, y);
			mlx_put_image_to_window(data.mlx, data.win, data.rocket.frnt, x, y);
		}
		i++;
		x += 64;
	}
	return ;
}

char	move_rocket(t_mlx_data *data)
{
	t_point	player;
	t_point	rocket;
	char	c;

	player = get_pos(data->area, 'P');
	rocket = get_pos(data->area, 'X');
	c = '\0';
	if (rocket.x > player.x && (data -> area[rocket.y][rocket.x - 1] == '0'
		|| data -> area[rocket.y][rocket.x - 1] == 'P'))
		c = 'a';
	else if (rocket.x < player.x && (data -> area[rocket.y][rocket.x + 1] == '0'
		|| data -> area[rocket.y][rocket.x + 1] == 'P'))
		c = 'd';
	else if (rocket.y > player.y && (data -> area[rocket.y - 1][rocket.x] == '0'
		|| data -> area[rocket.y - 1][rocket.x] == 'P'))
		c = 'w';
	else if (rocket.y < player.y && (data -> area[rocket.y + 1][rocket.x] == '0'
		|| data -> area[rocket.y + 1][rocket.x] == 'P'))
		c = 's';
	make_move(data, c, rocket.y, rocket.x);
	return (c);
}

void	make_move(t_mlx_data *data, char c, int y, int x)
{
	if (c == 'a')
	{
		data -> area[y][x] = '0';
		data -> area[y][x - 1] = 'X';
	}
	else if (c == 'd')
	{
		data -> area[y][x] = '0';
		data -> area[y][x + 1] = 'X';
	}
	else if (c == 'w')
	{
		data -> area[y][x] = '0';
		data -> area[y - 1][x] = 'X';
	}
	else if (c == 's')
	{
		data -> area[y][x] = '0';
		data -> area[y + 1][x] = 'X';
	}
}

int	player_catched(char **area)
{
	int		x;
	int		y;

	y = 0;
	while (area[y])
	{
		x = 0;
		while (area[y][x])
		{
			if (area[y][x] == 'P')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
