/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:49:10 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/29 17:03:02 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "libft/libft.h"
#include <mlx.h>

// TEMPORARY FUNCTIONS ///////////////////////////////////////////////////////////////
void print_map(t_global *g)
{
	int i;

	i = 0;
	printf("%s\n", " --------------- PRINT MAP----------------");
	while (g->map_data[i])
	{
		printf("map -> %s\n", g->map_data[i]);
		i++;
	}
}

void print_input_data(t_global *g)
{
	printf(" ------------ %d\n",g->window->x_resolution);
	printf(" ------------ %d\n",g->window->y_resolution);
	printf(" ------------ %s\n",g->map_textures->north_texture_path);
	printf(" ------------ %s\n",g->map_textures->south_texture_path);
	printf(" ------------ %s\n",g->map_textures->west_texture_path);
	printf(" ------------ %s\n",g->map_textures->east_texture_path);
	printf(" ------------ %s\n",g->map_textures->sprite_texture_path);
	printf(" ------------ %x\n",g->map_textures->floor_color);
	printf(" ------------ %x\n",g->map_textures->ceiling_color);
	printf("\nVALID PARAMS COUNT - %d\n\n",g->valid_parameter_count);
}

// MAIN ////////////////////////////////////////////////////////////////////////////////

int main()
{
	t_global *g;

	g = malloc(sizeof(t_global));
	if (!g)
		return (0);
	if (init_global_struct(g))
	{
		parse_input(g);
		/// DELETE ////////////////////////
		print_input_data(g);
		print_map(g);
		/// DELETE ////////////////////////
		if (*(g->error))
		{
			show_errors(g);
			free_everything(g);
			return (0);
		}
		mlx_entrypoint(g);
	}
	free_everything(g);
	return (0);
}
