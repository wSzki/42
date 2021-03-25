/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:50:27 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/25 21:15:42 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	check_neighbour(char **map, int x, int y, char c)
{
	if (c == 'N')
		x--;
	if (c == 'S')
		x++;
	if (c == 'W')
		y--;
	if (c == 'E')
		y++;
	if ((map[x][y] == ' ' || map[x][y] == '1'))
		return (1);
	return (0);
}

static int	check_nswe(char **map, int x, int y, int row_count)
{
	int flag;

	flag = 1;
	if (x == 0)
		if (check_neighbour(map, x, y, 'S'))
			if (check_neighbour(map, x, y, 'W'))
				if (check_neighbour(map, x, y, 'E'))
					flag = 0;
	if (x == row_count)
		if (check_neighbour(map, x, y, 'N'))
			if (check_neighbour(map, x, y, 'W'))
				if (check_neighbour(map, x, y, 'E'))
					flag = 0;
	if (x != 0 && x != row_count)
		if (check_neighbour(map, x, y, 'N'))
			if (check_neighbour(map, x, y, 'S'))
				if (check_neighbour(map, x, y, 'W'))
					if (check_neighbour(map, x, y, 'E'))
						flag = 0;
	return (flag);
}

void		check_walls(t_global *g, int row_count, int col_count)
{
	int		x;
	int		y;
	int		flag;
	char	**map;

	flag = 0;
	map = g->map_data;
	x = -1;
	while (map[++x] && x < row_count)
	{
		y = 0;
		while (map[x][++y] && y < col_count - 1)
			if (map[x][y] == ' ')
				flag += check_nswe(map, x, y, row_count - 1);
	}
	if (flag)
		append_error(g, "", "Invalid map - wall missing\n");
}
