/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:56:23 by ljussiau          #+#    #+#             */
/*   Updated: 2023/12/13 10:20:58 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_line(char *str, t_mlx_data data, int y)
{
	int		x;
	int		i;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			mlx_put_image_to_window(data.mlx, data.win, data.wall, x, y);
		else if (str[i] == 'E')
			mlx_put_image_to_window(data.mlx, data.win, data.exit, x, y);
		else if (str[i] == '0')
			mlx_put_image_to_window(data.mlx, data.win, data.floor, x, y);
		if (str[i] == 'C')
		{
			mlx_put_image_to_window(data.mlx, data.win, data.floor, x, y);
			mlx_put_image_to_window(data.mlx, data.win, data.key, x, y);
			data.nb_key++;
		}
		i++;
		x += 64;
	}
	return ;
}

void	ft_find_player(char *str, t_mlx_data data, int y, char c)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P' && c == 's')
			mlx_put_image_to_window(data.mlx, data.win, data.player.frnt, x, y);
		if (str[i] == 'P' && c == 'w')
			mlx_put_image_to_window(data.mlx, data.win, data.player.bck, x, y);
		if (str[i] == 'P' && c == 'a')
			mlx_put_image_to_window(data.mlx, data.win, data.player.lft, x, y);
		if (str[i] == 'P' && c == 'd')
			mlx_put_image_to_window(data.mlx, data.win, data.player.rght, x, y);
		if (str[i] == 'P' && c == 'b')
		{
			mlx_put_image_to_window(data.mlx, data.win, data.floor, x, y);
			mlx_put_image_to_window(data.mlx, data.win, data.player.frnt, x, y);
		}
		i++;
		x += 64;
	}
	return ;
}

void	ft_print_area(char **area, t_mlx_data data, char p, char r)
{
	int	y;
	int	i;

	data.floor = mlx_xpm_file_to_image(data.mlx, "asset/floor.xpm", &y, &i);
	data.wall = mlx_xpm_file_to_image(data.mlx, "asset/wall.xpm", &y, &i);
	data.exit = mlx_xpm_file_to_image(data.mlx, "asset/exit.xpm", &y, &i);
	data.key = mlx_xpm_file_to_image(data.mlx, "asset/ball.xpm", &y, &i);
	y = 0;
	i = 0;
	while (area[i] != NULL)
	{
		ft_print_line(area[i], data, y);
		i++;
		y += 64;
	}
	ft_print_rocket(area, data, r);
	ft_print_player(area, data, p);
	return ;
}

void	ft_print_player(char **area, t_mlx_data data, char c)
{
	int	y;
	int	i;

	data.player.frnt = mlx_xpm_file_to_image(data.mlx, FRONT, &y, &i);
	data.player.bck = mlx_xpm_file_to_image(data.mlx, BACK, &y, &i);
	data.player.lft = mlx_xpm_file_to_image(data.mlx, LEFT, &y, &i);
	data.player.rght = mlx_xpm_file_to_image(data.mlx, RIGHT, &y, &i);
	data.floor = mlx_xpm_file_to_image(data.mlx, "asset/floor.xpm", &y, &i);
	y = 0;
	i = 0;
	while (area[i] != NULL)
	{
		ft_find_player(area[i], data, y, c);
		i++;
		y += 64;
	}
	return ;
}
