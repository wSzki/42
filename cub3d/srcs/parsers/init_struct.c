/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:55:36 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/17 18:31:42 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_struct(t_global *g)
{
	g->error = 0;
	g->window->x_resolution = 0;
	g->window->y_resolution = 0;
	g->map_textures->north_texture_path = "";
	g->map_textures->south_texture_path = "";
	g->map_textures->east_texture_path = "";
	g->map_textures->west_texture_path = "";
	g->map_textures->sprite_texture_path = "";
	g->map_textures->floor_color = "";
	g->map_textures->ceiling_color = "";
	g->valid_parameter_count = 0;
}
