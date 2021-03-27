/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:33:15 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/27 16:33:29 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_everything(t_global *g)
{
	int i;

	// FREE MAP
	i = -1;
	while ((g->map_data)[++i])
		free((g->map_data)[i]);
	free(g->map_data);

	// FREE ERROR LIST
	i = -1;
	while ((g->error)[++i])
		free((g->error)[i]);
	free(g->error);

	// FREE MAP DATA
	free(g->map);

	// FREE WINDOW
	free(g->window);

	// FREE TEXTURES
	free(g->map_textures->north_texture_path);
	free(g->map_textures->south_texture_path);
	free(g->map_textures->east_texture_path);
	free(g->map_textures->west_texture_path);
	free(g->map_textures->sprite_texture_path);
	/*free(g->map_textures->floor_color);*/
	/*free(g->map_textures->ceiling_color);*/
	free(g->map_textures);
	free(g);
}
