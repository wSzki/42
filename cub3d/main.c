/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:49:10 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/27 16:39:56 by wszurkow         ###   ########.fr       */
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

// MLX //////////////////////////////////////////////////////////////////////////////////

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	/*char    *dst;*/


	// dst is the adress of the pixel to colorize
	// int offset = (y * line_length + x * (bits_per_pixel / 8));

	char *dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

////////////////////////////////////////////////////////////////////////////////////////

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
			if (g->map_data[x][y] == 'N')
			{
				i = 0;
				while (++i < square_size - 1)
				{
					j = 0;
					while (++j < square_size - 1)
					{
						my_mlx_pixel_put(img, i + square_size * x, j + square_size * y, g->map_textures->ceiling_color);
					}
				}
			}
			if (g->map_data[x][y] == '2')
			{
				i = 0;
				while (++i < square_size - 1)
				{
					j = 0;
					while (++j < square_size - 1)
					{
						my_mlx_pixel_put(img, i + square_size * x, j + square_size * y, 0x00191d20);
					}
				}

			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////

/*typedef struct  s_data {*/
	/*void        *img;*/
	/*void 		*win;*/
	/*char        *addr;*/
	/*int         bits_per_pixel;*/
	/*int         line_length;*/
	/*int         endian;*/
/*}               t_data;*/
void	mlx_function(t_global *g)
{
	void *mlx_ptr;
	void *win_ptr;
	t_data *img;

	img = malloc(sizeof(t_data));

	mlx_ptr = mlx_init(); // INIT MLX INSTANCE
	win_ptr = mlx_new_window(mlx_ptr, g->window->x_resolution , g->window->y_resolution, "name"); // POINT TO WINDOW
	img->img = mlx_new_image(mlx_ptr, g->window->x_resolution , g->window->y_resolution); // CREATE NEW IMAGE


	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian)); // POPULATE IMAGE

	ft_put_square(img, g);

	// SEND IMAGE TO WINDOW
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, 0, 0);

	// WINDOW STAY OPEN
	mlx_loop(mlx_ptr);

	// MEMORY CLEANUP
	mlx_destroy_image(mlx_ptr, img->img);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	free(img);
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
		mlx_function(g);
	}
	free_everything(g);
	return (0);
}
