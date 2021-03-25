/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:42:45 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/25 13:41:13 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	check_top_and_bottom(char **map, int line_count)
{
	int i;
	int flag;

	flag = 0;
	i = -1;
	while (map[0][++i])
		if (map[0][i] != ' ' && map[0][i] != '1')
			flag = 1;
	i = -1;
	while (map[line_count - 1][++i])
		if (map[line_count - 1][i] != ' ' && map[line_count - 1][i] != '1')
			flag = 1;
	return (flag);
}

static int	check_left_and_right(char **map, int largest_line)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1')
			flag = 1;
	}
	i = -1;
	while (map[++i])
	{
		j = largest_line - 1;
		while (map[i][j] == ' ')
			j--;
		if (map[i][j] != '1')
			flag = 1;
	}
	return (flag);
}

void		check_borders(t_global *g, int line_count, int largest_line)
{
	int		flag;
	char	**map;

	flag = 0;
	map = g->map_data;
	flag += check_top_and_bottom(map, line_count);
	flag += check_left_and_right(map, largest_line);
	if (flag)
		append_error(g, "", "Map is not correctly closed at borders\n");
}
