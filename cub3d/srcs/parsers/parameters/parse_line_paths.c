/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:53:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/24 15:24:04 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"


static void free_all(char **str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free (str);
	str = NULL;
}

static void rgb_to_hex(int r, int g, int b, char *id, t_global *global)
{
	unsigned int t;

	t = 0;

	if (ft_strcmp(id, "F") == 0)
		global->map_textures->floor_color = (t << 24 | r << 16 | g << 8 | b);
	if (ft_strcmp(id, "C") == 0)
		global->map_textures->ceiling_color = (t << 24 | r << 16 | g << 8 | b);
}

static	void	parse_rgb(char *id, char *rgb_str, t_global *g)
{
	char **rgb_split;

	rgb_split = ft_split(rgb_str, ',');
	if (number_of_args(rgb_split) == 3)
	{
		if (ft_is_number(rgb_split[0]))
			if (ft_is_number(rgb_split[1]))
				if (ft_is_number(rgb_split[2]))
				{
					rgb_to_hex(\
							ft_atoi(rgb_split[0]), \
							ft_atoi(rgb_split[1]), \
							ft_atoi(rgb_split[2]), \
							id, g);
					g->valid_parameter_count++;
					free_all(rgb_split);
					return ;
				}
		append_error(g, id, " : only takes numbers\n");
		free_all(rgb_split);
		return ;
	}
	append_error(g, id, " : wrong number of arguments\n");
	free_all(rgb_split);
	return ;
}

static	void	process_path(char **line_split, char **path_ptr, t_global *g)
{
	if (!path_ptr)
		return ;
	if (*path_ptr == NULL)
	{
		*path_ptr = ft_strdup(line_split[1]);
		g->valid_parameter_count++;
	}
	else
		append_error(g, line_split[0], " : path already set\n");
}

void			parse_line_paths(char **line_split, t_global *g)
{
	if (!line_split)
		return;
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
		parse_rgb("F", line_split[1], g);
	else if (ft_strcmp(line_split[0], "C") == 0)
		parse_rgb("C", line_split[1], g);
	else
		append_error(g, line_split[0], " wrong parameter ID\n");
}
