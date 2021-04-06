/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_entrypoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:00:12 by wszurkow          #+#    #+#             */
/*   Updated: 2021/04/06 18:54:27 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define ESC 65307
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364

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

void	ft_put_square(t_global *g)
{
	int i;
	int j;
	int x;
	int y;


	int square_size = 0;
	if (g->window->x_resolution > g->window->y_resolution)
		square_size = g->window->x_resolution / g->map->number_columns;
	else
		square_size = g->window->y_resolution / g->map->number_rows;


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
						my_mlx_pixel_put(g->data, i + square_size * x, j + square_size * y, g->map_textures->floor_color);
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
						my_mlx_pixel_put(g->data, i + square_size * x, j + square_size * y, g->map_textures->ceiling_color);
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
						my_mlx_pixel_put(g->data, i + square_size * x, j + square_size * y, 0x00191d20);
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

int key_hook(int keycode, t_global *g )
{
	/*printf("%d\n", keycode);*/
	/*if (keycode == ESC)*/
	/*printf("%s\n", "Escape");*/
	/*if (keycode == UP)*/
	/*{*/
	/*printf("%s\n", "Escape");*/
	/*printf("%p\n", g);*/

	/*printf("%d\n", g->window->x_resolution);*/
	/*}*/
(void)keycode;
	/*if (keycode == UP)*/
		static int i;
	mlx_destroy_image(g->mlx, g->data->img);
	g->data->img = mlx_new_image(\
			g->mlx, \
			g->window->x_resolution , \
			g->window->y_resolution);

	g->data->addr = mlx_get_data_addr(\
			g->data->img, \
			&(g->data->bits_per_pixel), \
			&(g->data->line_length), \
			&(g->data->endian));
		my_mlx_pixel_put(g->data,  i + 100 , 200, 0x00FFFFFFFF);
	mlx_put_image_to_window(g->mlx, g->win, g->data->img, 0, 0);
		i++;

		printf("%d\n", i);
	return 1;
}

int	loop_hook(void *param)
{
	(void)param;

	printf("%s\n", "hello");
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

	// INIT MLX //////////////////////////////
	g->data = malloc(sizeof(t_data));
	if (!(g->data))
		return ;
	g->mlx = mlx_init(); // INIT MLX INSTANCE
	g->win = mlx_new_window(\
			g->mlx, \
			g->window->x_resolution, \
			g->window->y_resolution, \
			"name");

	// CREATE IMG + ADDR + POPULATE //////////
	g->data->img = mlx_new_image(\
			g->mlx, \
			g->window->x_resolution , \
			g->window->y_resolution);

	g->data->addr = mlx_get_data_addr(\
			g->data->img, \
			&(g->data->bits_per_pixel), \
			&(g->data->line_length), \
			&(g->data->endian));

	// DRAW SQUARES /////////////////////////
	ft_put_square(g);
	/*mlx_key_hook(g->win, key_hook, g);*/
	/*mlx_key_hook(g->win, key_hook, g);*/
	// SEND IMAGE TO WINDOW /////////////////
	mlx_key_hook(g->win, key_hook, g);
	mlx_put_image_to_window(g->mlx, g->win, g->data->img, 0, 0);


	// KEY HOOK /////////////////////////////
	/*mlx_mouse_hook(win_ptr, key_hook, img);*/
	/*mlx_expose_hook(win_ptr, key_hook, img);*/
	//

	// DESTROY WINDOW SHORTCUT
	/*mlx_key_hook(win_ptr, close_window, mlx_ptr);*/


	// WINDOW STAY OPEN
	mlx_loop(g->mlx);
	exit(0);

	// MEMORY CLEANUP
	/*mlx_destroy_image(mlx_ptr, img->img);*/
	/*mlx_destroy_window(mlx_ptr, win_ptr);*/
	/*mlx_destroy_display(mlx_ptr);*/
	/*free(mlx_ptr);*/
	/*free(img);*/
}

