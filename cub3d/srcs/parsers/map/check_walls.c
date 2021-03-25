/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:50:27 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/25 14:12:50 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	check_nsew(char **map, int i, int j)
{
	int flag;

	flag = 0;
	if (!((map[i - 1][j] == ' ' || map[i - 1][j] == '1') && \
				(map[i + 1][j] == ' ' || map[i + 1][j] == '1') && \
				(map[i][j - 1] == ' ' || map[i][j - 1] == '1') && \
				(map[i][j + 1] == ' ' || map[i][j + 1] == '1')))
		flag = 1;
	return (flag);
}

static int	check_nsew_top_bottom(char **map, int i, int j, char c)
{
	int flag;

	flag = 0;
	if (c == 'T')
		if (!((map[i + 1][j] == ' ' || map[i + 1][j] == '1') && \
					(map[i][j - 1] == ' ' || map[i][j - 1] == '1') && \
					(map[i][j + 1] == ' ' || map[i][j + 1] == '1')))
			flag = 1;
	if (c == 'B')
		if (!((map[i - 1][j] == ' ' || map[i - 1][j] == '1') && \
					(map[i][j - 1] == ' ' || map[i][j - 1] == '1') && \
					(map[i][j + 1] == ' ' || map[i][j + 1] == '1')))
			flag = 1;
	return (flag);
}

static int		check_first_and_last_line(t_global *g, int row, int column)
{
	int i;
	int flag;
	char	**map;

	i = 0;
	flag = 0;

	map = g->map_data;
	while (map[0][++i] && i < column - 1)
	{
		if (map[0][i] == ' ')
			flag += check_nsew_top_bottom(map, 0, i, 'T');
	}
	i = 0;
	while (map[row - 1][++i] && i < column - 1)
	{

		if (map[row - 1][i] == ' ')
			flag += check_nsew_top_bottom(map, row - 1, i, 'B');
	}
	(void)row;
	return (flag);
}

void		check_walls(t_global *g, int line_count, int largest_line)
{
	int		i;
	int		j;
	int		flag;
	char	**map;

	flag = 0;
	map = g->map_data;
	i = 0;
	while (map[++i] && i < line_count - 1)
	{
		j = 0;
		while (map[i][++j] && j < largest_line - 1)
		{
			if (map[i][j] == ' ')
				flag += check_nsew(map, i, j);
		}
	}
	flag += check_first_and_last_line(g, line_count, largest_line);
	if (flag)
		append_error(g, "", "Invalid map within borders\n");
}
