/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 07:32:14 by ljussiau          #+#    #+#             */
/*   Updated: 2023/12/12 10:15:24 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_point	get_posi(t_point begin, int n)
{
	t_point	pos;

	if (n == 0)
	{
		pos.x = begin.x - 1;
		pos.y = begin.y;
	}
	if (n == 1)
	{
		pos.x = begin.x + 1;
		pos.y = begin.y;
	}
	if (n == 2)
	{
		pos.x = begin.x;
		pos.y = begin.y - 1;
	}
	if (n == 3)
	{
		pos.x = begin.x;
		pos.y = begin.y + 1;
	}
	return (pos);
}

static int	checker(char tab, t_map_bool *map)
{
	if (tab == 'P')
	{
		map -> nb_start += 1;
		return (0);
	}
	if (tab == 'C')
	{
		map -> nb_key += 1;
		return (0);
	}
	if (tab == 'E')
	{
		map -> nb_exit += 1;
		return (0);
	}
	if (tab == '0')
		return (0);
	return (tab);
}

void	flood_fill(char **tab, t_point size, t_point begin, t_map_bool *mp)
{
	tab[begin.y][begin.x] = ' ';
	if (begin.x > 0 && checker(tab[begin.y][begin.x - 1], mp) == 0)
		flood_fill(tab, size, get_posi(begin, 0), mp);
	if (begin.x < (size.x - 1) && checker(tab[begin.y][begin.x + 1], mp) == 0)
		flood_fill(tab, size, get_posi(begin, 1), mp);
	if (begin.y > 0 && checker(tab[begin.y - 1][begin.x], mp) == 0)
		flood_fill(tab, size, get_posi(begin, 2), mp);
	if (begin.y < (size.y - 1) && checker(tab[begin.y + 1][begin.x], mp) == 0)
		flood_fill(tab, size, get_posi(begin, 3), mp);
}
