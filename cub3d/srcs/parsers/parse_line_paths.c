/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:53:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/16 02:49:54 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"



static int	number_of_args(char **line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}


void	parse_line_paths(char *line, t_global *g)
{
	char **line_split;

	if (line == NULL || *line == '\0')
		return ;
	line_split = ft_split(line, ' ');
	if (line_split == NULL)
		return;
	if 	(number_of_args(line_split) == 2)
	{
		if (ft_strcmp(line_split[0], "NO") == 0)
			g->map_textures->north_texture_path = line_split[1];
		if (ft_strcmp(line_split[0], "SO") == 0)
			g->map_textures->south_texture_path = ft_strdup(line_split[1]);
		if (ft_strcmp(line_split[0], "WE") == 0)
			g->map_textures->west_texture_path = ft_strdup(line_split[1]);
		if (ft_strcmp(line_split[0], "EA") == 0)
			g->map_textures->east_texture_path = ft_strdup(line_split[1]);
		if (ft_strcmp(line_split[0], "S") == 0)
			g->map_textures->sprite_texture_path = ft_strdup(line_split[1]);
		if (ft_strcmp(line_split[0], "F") == 0)
			g->map_textures->floor_color = ft_strdup(line_split[1]);
		if (ft_strcmp(line_split[0], "C") == 0)
			g->map_textures->ceiling_color = ft_strdup(line_split[1]);
	}
	free(line_split);
}
