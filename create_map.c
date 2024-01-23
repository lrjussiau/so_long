/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:45:22 by ljussiau          #+#    #+#             */
/*   Updated: 2023/12/13 09:50:05 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(int fd)
{
	char	*temp_map;
	char	*str;

	temp_map = ft_strdup("");
	while (1)
	{		
		str = get_next_line(fd);
		if (str == NULL)
		{
			free(str);
			break ;
		}
		temp_map = ft_strappend(&temp_map, str);
		free (str);
	}
	close(fd);
	return (temp_map);
}

char	**create_area(char *path_map)
{
	int		fd;
	char	*temp_map;
	char	**map;

	fd = open(path_map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nFailed to open FD");
		return (NULL);
	}
	temp_map = read_map(fd);
	map = ft_split(temp_map, '\n');
	free (temp_map);
	if (check_char(map) != 0)
		return (NULL);
	return (map);
}

char	**create_map(char *path)
{
	char		**area;
	t_point		size;
	t_point		begin;
	t_map_bool	*map;

	map = NULL;
	area = create_area(path);
	if (area == NULL)
		return (NULL);
	map = init_map_bool(map);
	size = get_size(area);
	begin = get_begin(area, map);
	flood_fill(area, size, begin, map);
	check_wall(area, size, map);
	ft_free_tab(area);
	if (map_validate(map) == 0)
	{
		free(map);
		area = create_area(path);
		return (area);
	}
	free(map);
	return (NULL);
}
