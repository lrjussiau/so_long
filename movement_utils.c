/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:12:11 by ljussiau          #+#    #+#             */
/*   Updated: 2023/12/13 10:23:47 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	get_pos(char **map, char c)
{
	t_point	pos;
	int		x;
	int		y;

	y = 0;
	pos.x = 0;
	pos.y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
			{
				pos.x = x;
				pos.y = y;
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (pos);
}

int	get_nb_key(char **map)
{
	int		key;
	int		x;
	int		y;

	y = 0;
	key = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				key++;
			}
			x++;
		}
		y++;
	}
	return (key);
}

void	move_player(t_mlx_data *data, char c, int y, int x)
{
	if (data -> last_case == 'E')
		data -> area[y][x] = data -> last_case;
	else
		data -> area[y][x] = '0';
	if (c == 'w')
	{
		data->last_case = data->area[y - 1][x];
		data -> area[y - 1][x] = 'P';
	}
	if (c == 'a')
	{
		data->last_case = data->area[y][x - 1];
		data -> area[y][x - 1] = 'P';
	}
	if (c == 's')
	{
		data->last_case = data->area[y + 1][x];
		data -> area[y + 1][x] = 'P';
	}
	if (c == 'd')
	{
		data->last_case = data->area[y][x + 1];
		data -> area[y][x + 1] = 'P';
	}
	return ;
}

int	check_if_wall(t_mlx_data *data, char c, int y, int x)
{
	if (c == 'w')
	{
		if (data -> area[y - 1][x] == '1')
			return (1);
	}
	if (c == 'a')
	{
		if (data -> area[y][x - 1] == '1')
			return (1);
	}
	if (c == 's')
	{
		if (data -> area[y + 1][x] == '1')
			return (1);
	}
	if (c == 'd')
	{
		if (data -> area[y][x + 1] == '1')
			return (1);
	}
	return (0);
}
