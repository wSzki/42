/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_entrypoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:00:12 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/29 17:01:39 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int key_hook(int keycode, t_data *img)
{
	(void)img;
	printf("%d\n", keycode);
	return 1;
}

int close_window(int keycode, void *mlx_ptr, void *win_ptr)
{
	(void)keycode;
	mlx_destroy_window(mlx_ptr, win_ptr);
	return 1;
}

void	mlx_entrypoint(t_global *g)
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


	// KEY HOOK
	mlx_key_hook(win_ptr, key_hook, img);


	//
	mlx_mouse_hook(win_ptr, key_hook, img);
	mlx_expose_hook(win_ptr, key_hook, img);
	mlx_loop_hook(win_ptr, key_hook, img);
	//

	// DESTROY WINDOW SHORTCUT
	mlx_key_hook(win_ptr, close_window, mlx_ptr);


	// WINDOW STAY OPEN
	mlx_loop(mlx_ptr);
	exit(0);

	// MEMORY CLEANUP
	mlx_destroy_image(mlx_ptr, img->img);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	free(img);
}

