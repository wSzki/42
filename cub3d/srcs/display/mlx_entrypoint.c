/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_entrypoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:00:12 by wszurkow          #+#    #+#             */
/*   Updated: 2021/04/08 20:36:55 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define ESC 65307
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364

// TRASH //////////////////////////////////////////////////////////////////////////////////
/*
   typedef struct  s_data {
   void        *img;
   void 		*win;
   char        *addr;
   int         bits_per_pixel;
   int         line_length;
   int         endian;
   }               t_data;

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

   void malloc_safe(void *ptr, int type)
   {
   ptr = malloc(type);
   if (!ptr)
   {
   ft_putstr("Insufficient Memory");
   exit (0);
   }
   }


*/
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
						my_mlx_pixel_put(g->minimap, i + square_size * x, j + square_size * y, g->map_textures->floor_color);
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
						my_mlx_pixel_put(g->minimap, i + square_size * x, j + square_size * y, 0x22191d20);
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
						my_mlx_pixel_put(g->minimap, i + square_size * x, j + square_size * y, 0xFF191d20);
					}
				}

			}
		}
	}
}

void	display_minimap(t_global *g)
{
	int square_size;

	square_size = g->window->x_resolution / g->map->number_columns;

	printf("%d\n", g->window->x_resolution);
int i;
	int j ;

	i = -1;
	while (++i < square_size)
	{
		j = -1;
		while (++j < square_size - 1)
		{
			my_mlx_pixel_put(g->minimap, i + square_size , j + square_size, 0xFF191d20);
		}
	}


}


void	init_image_test(t_global *g, t_data *data)
{
	data->img = mlx_new_image(\
			g->mlx, \
			40 , \
			40);

	data->addr = mlx_get_data_addr(\
			data->img, \
			&(data->bits_per_pixel), \
			&(data->line_length), \
			&(data->endian));

			my_mlx_pixel_put(g->buffer, 5 , 5, 0x00FF1FF0);

}

/////////////////////////////////////////////////////////////////////////////////

void	mlx_entrypoint(t_global *g)
{

	// INIT MLX //////////////////////////////
	init_mlx_struct(g);
	init_mlx(g);
	init_image(g, g->minimap);
	init_image_test(g, g->buffer);
	display_minimap(g);


	// DRAW SQUARES /////////////////////////
	/*ft_put_square(g);*/
	/*mlx_key_hook(g->win, key_hook, g);*/
	/*mlx_key_hook(g->win, key_hook, g);*/
	// SEND IMAGE TO WINDOW /////////////////
	mlx_put_image_to_window(g->mlx, g->win, g->minimap->img, 0, 0);
	mlx_put_image_to_window(g->mlx, g->win, g->buffer->img, 0, 0);

	/*draw_minimap(g);*/
	/*mlx_key_hook(g->win, key_hook, g);*/

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

