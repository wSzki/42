/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_resolution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:48:12 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/16 02:47:50 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_line_resolution(char *line, t_global *g)
{
	char **line_split;

	line_split = NULL;
	if (!line || *line == '\0')
		return ;
	line_split = ft_split(line, ' ');
	if (!line_split)
		return ;
	if (ft_strcmp(line_split[0], "R") == 0)
	{
		if (g->window->x_resolution || g->window->y_resolution)
		{
			g->error = 1;
			return ;
		}
		if ((ft_is_number(line_split[1]) && ft_is_number(line_split[2])))
			if (line_split[3] == NULL)
			{
				g->window->x_resolution = ft_atoi(line_split[1]);
				g->window->y_resolution = ft_atoi(line_split[2]);
				return ;
			}
		g->error = 1;
		return ;
	}
	free(line_split);
}

