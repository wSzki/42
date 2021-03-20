/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:50:27 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/20 22:05:49 by wszurkow         ###   ########.fr       */
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
	if (flag)
		append_error(g, "", "Invalid map within borders\n");
}
