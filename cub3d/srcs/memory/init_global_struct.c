/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:32:07 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/27 16:33:06 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		init_global_struct(t_global *g)
{
	// ERROR LIST
	g->error = malloc(sizeof(char *));
	if (!(g->error))
		return (0);
	*(g->error) = NULL;
	g->valid_parameter_count = 0;

	// WINDOW
	g->window = malloc(sizeof(t_window));
	g->window->x_resolution = -1;
	g->window->y_resolution = -1;

	// MAP INFO
	g->map = malloc(sizeof (t_map));

	// TEXTURES
	g->map_textures = malloc(sizeof(t_map_textures));
	g->map_textures->north_texture_path = NULL;
	g->map_textures->south_texture_path = NULL;
	g->map_textures->east_texture_path = NULL;
	g->map_textures->west_texture_path = NULL;
	g->map_textures->sprite_texture_path = NULL;
	g->map_textures->floor_color = -1;
	g->map_textures->ceiling_color = -1;

	// MAP
	g->map_data = malloc(sizeof(char *));
	if (!(g->map_data))
		return (0);
	*(g->map_data) = NULL;
	return (1);
}
