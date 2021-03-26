/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:49:10 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/26 12:06:11 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "libft/libft.h"

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

//// MEMORY ALLOCATION ////////////////////////////////////////////////////////////////
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

// MEMORY FREE /////////////////////////////////////////////////////////////////////////

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

// UTILS ////////////////////////////////////////////////////////////////////////////////

void show_errors(t_global *g)
{
	printf("Error\n");
	int i = -1;
	if (*(g->error))
	{
		while (((g->error)[++i]) != NULL)
			ft_putstr((g->error)[i]);
	}
}

// MLX //////////////////////////////////////////////////////////////////////////////////

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	/*char    *dst;*/


	// dst is the adress of the pixel to colorize
	// int offset = (y * line_length + x * (bits_per_pixel / 8));

	char *dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_put_square(t_data *img, t_global *g)
{
	int i;
	int j;


	int square_size = 0;
	if (g->window->x_resolution > g->window->y_resolution)
		square_size = g->window->x_resolution / g->map->number_columns;
	else
		square_size = g->window->y_resolution / g->map->number_rows;


	printf("square %d\n", square_size);

	int x;
	int y;

	x = -1;
	y = -1;
	while (g->map_data[++x])
	{
		y = -1;
		while (g->map_data[x][++y])
		{
			if (g->map_data[x][y] == '1')
			{
				i = 0;
				while (++i < square_size - 1)
				{
					j = 0;
					while (++j < square_size - 1)
					{
						my_mlx_pixel_put(img, i + square_size * x, j + square_size * y, g->map_textures->floor_color);
					}
				}
			}
		}
	}
}

void	mlx_function(t_global *g)
{
	void *mlx;
	void *win_ptr;
	t_data img;

	// INIT MLX INSTANCE
	mlx = mlx_init();

	// POINT TO WINDOW
	win_ptr = mlx_new_window(mlx, g->window->x_resolution , g->window->y_resolution, "name");

	// CREATE NEW IMAGE
	img.img = mlx_new_image(mlx, g->window->x_resolution , g->window->y_resolution);

	// POPULATE IMAGE
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	ft_put_square(&img, g);

	// SEND IMAGE TO WINDOW
	mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);

	// WINDOW STAY OPEN
	mlx_loop(mlx);
}

// MAIN ////////////////////////////////////////////////////////////////////////////////

int main()
{
	// Location of current MLX instance
	t_global *g;

	g = malloc(sizeof(t_global));
	if (!g)
		return (0);
	if (init_global_struct(g))
	{
		parse_input(g);
		///////////////////////////
		print_input_data(g);
		print_map(g);
		///////////////////////////
		if (*(g->error))
		{
			show_errors(g);
			free_everything(g);
			return (0);
		}
		/*mlx_function(g);*/
	}
	free_everything(g);
	return (0);
}
