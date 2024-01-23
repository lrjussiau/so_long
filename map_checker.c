/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:06:24 by ljussiau          #+#    #+#             */
/*   Updated: 2023/12/13 09:46:52 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_begin(char **map, t_map_bool *map_bool)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				map_bool -> nb_start += 1;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	check_wall(char **map, t_point size, t_map_bool *map_bool)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (x < size.x)
	{
		if (map[0][x] != '1' || map[size.y][x] != '1')
			return ;
		x++;
	}
	while (y < size.y)
	{
		if (map[y][0] != '1' || map[y][size.x] != '1')
			return ;
		y++;
	}
	map_bool -> is_walled = true;
	return ;
}

int	map_validate(t_map_bool *map)
{
	if (map -> nb_start > 1 || map -> nb_exit > 1)
	{
		if (map -> nb_start > 1)
			perror("Error\nTo much 'P' in the Map");
		if (map -> nb_exit > 1)
			perror("Error\nTo much 'E' in the Map");
		return (1);
	}
	if (map -> is_walled == false)
	{
		perror("Error\nMap is not surrond by wall");
		return (1);
	}
	else
	{
		if (map -> nb_exit == 1 && map -> nb_start == 1 && map -> nb_key > 0)
			map -> is_possible = true;
	}
	if (map -> is_possible == false)
	{
		perror("Error\nMap can not be done");
		return (1);
	}
	return (0);
}
