/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:30:54 by wszurkow          #+#    #+#             */
/*   Updated: 2021/07/17 03:03:14 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_draw_line(t_global *g, void *mlx, void *win)
{

	printf("%d\n", g->start_x);
	printf("%d\n", g->start_y);
	printf("%d\n", g->end_x);
	printf("%d\n", g->end_y);
	mlx_pixel_put(mlx, win, g->start_x, g->start_y, 0x00FFFFFF);
	mlx_pixel_put(mlx, win, g->end_x, g->end_y, 0x00FFFFFF);



	printf("Line is %d pixels long \n", g->end_x - g->start_x);
	printf("Line must be cut to fit %d pixels \n", g->end_y - g->start_y);
	printf("%d\n", (g->end_x - g->start_x) / (g->end_y - g->start_y));

	printf("%d\n", 35/13);
	printf("%d\n", 35%13);

	int i = g->start_x;

	while (i < g->end_x)
	{
		mlx_pixel_put(mlx, win, i, g->start_y, 0x00FABD2F);
		i++;
	}
}



void	fdf_mlx_start(t_global *g)
{

	// INIT ------------------------------
	void *mlx;
	void *win;
	void *img;













	/*char *data;*/
	/*int bits_per_pixel;*/
	/*int size_line;*/
	/*int endian;*/

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "window");
	img = mlx_new_image(mlx, 500, 500);
	/*data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);*/


	//////////////////////////////////////////////
	t_line *line;
	line = malloc(sizeof(*line));

	line->x_start = 32;
	line->y_start = 56;
	line->x_end = 400;
	line->y_end = 172;

	mlx_pixel_put(mlx, win, line->x_start, line->y_start, 0x00FFFFFF);
	mlx_pixel_put(mlx, win, line->x_end, line->y_end, 0x00FFFFFF);

	while (line->x_start < line->x_end)
	{
		mlx_pixel_put(mlx, win, line->x_start, line->y_start, 0x00FABD2F);
		line->x_start++;
		if (line->x_start % (line->x_end / line->y_end ) == 0)
			line->y_start += 1;
	}

	//////////////////////////////////////////////


	g->start_x = 10;
	g->start_y = 10;

	g->end_x = 45;
	g->end_y = 23;
	/*fdf_draw_line(g, mlx, win);*/

	/*int i = 0;*/
	/*int j = 1;*/

	/*while (i < 100)*/
	/*{*/
	/*mlx_pixel_put(mlx, win, i, j, 0x00FFFFFF);*/
	/*if (i % 2 == 0)*/
	/*{*/
	/*j = j * 4 / 3;*/
	/*}*/
	/*i++;*/
	/*}*/
	/*mlx_string_put(mlx, win, 25, 25, 11160, "Hello");*/
	mlx_put_image_to_window(mlx, win, img, 500, 500);
	mlx_loop(mlx);
	// FREE -------------------------------
	mlx_destroy_image(mlx, img);
	mlx_destroy_window(mlx, win);
	free(mlx);
	fdf_print_map(g);
	return ;
}
