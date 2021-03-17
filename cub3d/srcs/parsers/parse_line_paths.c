/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:53:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/17 18:23:24 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void	process_path(char **line_split, char **path_ptr, t_global *g)
{
	if (**path_ptr == '\0')
	{
		*path_ptr = ft_strdup(line_split[1]);
		g->valid_parameter_count++;
	}
	else
		g->error = 1;
}

void			parse_line_paths(char **line_split, t_global *g)
{
	if (ft_strcmp(line_split[0], "NO") == 0)
		process_path(line_split, &(g->map_textures->north_texture_path), g);
	else if (ft_strcmp(line_split[0], "SO") == 0)
		process_path(line_split, &(g->map_textures->south_texture_path), g);
	else if (ft_strcmp(line_split[0], "WE") == 0)
		process_path(line_split, &(g->map_textures->west_texture_path), g);
	else if (ft_strcmp(line_split[0], "EA") == 0)
		process_path(line_split, &(g->map_textures->east_texture_path), g);
	else if (ft_strcmp(line_split[0], "S") == 0)
		process_path(line_split, &(g->map_textures->sprite_texture_path), g);
	else if (ft_strcmp(line_split[0], "F") == 0)
		process_path(line_split, &(g->map_textures->floor_color), g);
	else if (ft_strcmp(line_split[0], "C") == 0)
		process_path(line_split, &(g->map_textures->ceiling_color), g);
	else
		g->error = 1;
}
