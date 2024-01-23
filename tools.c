/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:10:07 by ljussiau          #+#    #+#             */
/*   Updated: 2023/12/13 09:50:30 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	get_size(char **map)
{
	t_point	size;
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	x = (ft_strlen(map[i]) - 1);
	while (map[i] != NULL)
	{
		i++;
		y++;
	}
	size.x = x - 1;
	size.y = y - 1;
	return (size);
}

t_point	get_begin(char **map, t_map_bool *map_bool)
{
	t_point	begin;
	int		x;
	int		y;

	y = 0;
	begin.x = 1;
	begin.y = 1;
	if (check_begin(map, map_bool) == 0)
		return (begin);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				begin.x = x;
				begin.y = y;
				return (begin);
			}
			x++;
		}
		y++;
	}
	return (begin);
}

t_map_bool	*init_map_bool(t_map_bool *map)
{
	map = (t_map_bool *)malloc(sizeof(t_map_bool));
	map -> is_possible = false;
	map -> is_walled = false;
	map -> nb_exit = 0;
	map -> nb_start = 0;
	map -> nb_key = 0;
	return (map);
}

char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

int	check_char(char **area)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (area[y] != NULL)
	{
		x = 0;
		while (area[y][x] != '\0')
		{
			c = area[y][x];
			if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C'
				&& c != 'X' && c != 13)
			{
				ft_free_tab(area);
				perror("Error\nWrong Charactere in the map");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
