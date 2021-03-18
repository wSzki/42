/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:49:10 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/18 15:31:21 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "libft/libft.h"

void init_global_struct(t_global *g)
{
	// Errors
	g->error = malloc(sizeof(char*));
	*(g->error) = NULL;
	g->valid_parameter_count = 0;

	// Window
	g->window = malloc(sizeof(t_window));
	g->window->x_resolution = 0;
	g->window->y_resolution = 0;

	// Textures
	g->map_textures = malloc(sizeof(t_map_textures));
	g->map_textures->north_texture_path = "";
	g->map_textures->south_texture_path = "";
	g->map_textures->east_texture_path = "";
	g->map_textures->west_texture_path = "";
	g->map_textures->sprite_texture_path = "";
	g->map_textures->floor_color = "";
	g->map_textures->ceiling_color = "";

	// Map
	g->map = malloc(sizeof(t_map));
	g->map->map_data = malloc(sizeof(t_map));
	*(g->map->map_data) = NULL;
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
	printf(" ------------ %s\n",g->map_textures->floor_color);
	printf(" ------------ %s\n",g->map_textures->ceiling_color);
	printf("valid parameters - %d\n",g->valid_parameter_count);
}


int main()
{
	// Location of current MLX instance
	void *mlx;
	t_window window;
	t_data img;
	void *win_ptr;


	t_global *g;

	g = malloc(sizeof(t_global));
	if (!g)
		return (-1);
	init_global_struct(g);


	parse_input(g);
	print_input_data(g);

	printf("\n#####################################\n");
	printf("# HERE ARE YOUR ERRORS MOTHERFUCKER #\n");
	printf("#####################################\n\n");
	int i = -1;
	if (g->valid_parameter_count != 8)
		printf("NOT ENOUGH VALID PARAMETERS (%d)\n", g->valid_parameter_count);
	if (*(g->error))
	{
		while (((g->error)[++i]))
			printf("%s", (g->error)[i]);
	}
	printf("\n#####################################\n");


	window.x_resolution = 300;
	window.y_resolution = 400;

	// INIT MLX INSTANCE
	mlx = mlx_init();

	// POINT TO WINDOW
	win_ptr = mlx_new_window(mlx, window.x_resolution , window.y_resolution, "name");

	// CREATE NEW IMAGE
	img.img = mlx_new_image(mlx, window.x_resolution , window.y_resolution);

	// POPULATE IMAGE
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// SEND IMAGE TO WINDOW
	mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);

	// WINDOW STAY OPEN
	mlx_loop(mlx);

	return (0);
}
