/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:43:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/18 15:30:08 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_map(char *line, int fd, t_global *g)
{
	int i;

	i = 0;
	while ((get_next_line(&line, fd) > 0))
	{
		if (detect_map_line(line) == 0)
			break ;
		g->map->map_data = dual_realloc(g->map->map_data, line);
	}
	while ((get_next_line(&line, fd) > 0))
	{
		if (*line != '\0')
			g->error = dual_realloc(g->error,\
					"Invalid map, line in middle or wrong data\n");
	}
	printf("%s\n", " --------------- PRINT MAP----------------");
	while (g->map->map_data[i])
	{
		printf("map -> %s\n", g->map->map_data[i]);
		i++;
	}
}
