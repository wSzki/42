/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:30:54 by wszurkow          #+#    #+#             */
/*   Updated: 2021/07/19 15:25:20 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_vertical_line(t_global *g, int x0, int y0, int x1, int y1)
{
	int tmp;

	(void)x1;
	if (y0 > y1)
	{
		tmp = y0;
		y0 = y1;
		y1 = tmp;
	}
	while (y0 < y1)
	{
		mlx_pixel_put(g->mlx, g->win, x0, y0, 0x00FFFFFF);
		y0++;
	}
}

void	fdf_horizontal_line(t_global *g, int x0, int y0, int x1, int y1)
{
	int tmp;

	(void)y1;
	if (x0 > x1)
	{
		tmp = x0;
		x0 = x1;
		x1 = tmp;
	}
	while (x0 < x1)
	{
		mlx_pixel_put(g->mlx, g->win, x0, y0, 0x00FFFFFF);
		x0++;
	}
}
void fdf_bresenham_line(t_global *g, int x0, int y0, int x1, int y1)
{
	int x;
	int y;
	int p;

	x = abs(x1 - x0);
	y = abs(y1 - y0);
	p = 2 * x - y;
	while (x0 < x1)
	{
		mlx_pixel_put(g->mlx, g->win, x0, y0, 0x00FFFFFF);
		if (p >= 0)
		{
			p += (2 * y) - (2 * x);
			y0++;
		}
		else
			p += 2 * y;
		x0++;
	}
}

void fdf_reverse_bresenham_line(t_global *g, int x0, int y0, int x1, int y1)
{
	int x;
	int y;
	int p;

	x = abs(x1 - x0);
	y = abs(y1 - y0);
	p = 2 * x - y;
	while (x0 < x1)
	{
		mlx_pixel_put(g->mlx, g->win, x0, y0, 0x00FABD2F);
		if (p >= 0)
		{
			y0--;
			p += (2 * y) - (2 * x);
		}
		else
			p += 2 * y;
		x0++;
	}
}

void	fdf_draw_line(t_global *g, int x0, int y0, int x1, int y1)
{
	int tmp;

	if (x0 > x1)
	{
		tmp = x0;
		x0 = x1;
		x1 = tmp;
		tmp = y0;
		y0 = y1;
		y1 = tmp;
	}
	if ((x0 - x1) == 0 && (y0 - y1) == 0)
		mlx_pixel_put(g->mlx, g->win, x0, y0, 0x00FABD2F);
	/*else if ((x0 - x1) == 0)*/
		/*fdf_vertical_line(g, x0, y0, x1, y1);*/
	else if ((y0 - y1) == 0)
		fdf_horizontal_line(g, x0, y0, x1, y1);
	else if (y0 < y1)
		fdf_bresenham_line(g, x0, y0, x1, y1);
	else if (y0 > y1)
		fdf_reverse_bresenham_line(g, x0, y0, x1, y1);

}


void	fdf_mlx_start(t_global *g)
{

	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 500, 500, "window");
	g->img = mlx_new_image(g->mlx, 500, 500);
	/*data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);*/

	/*fdf_draw_line(g, 10, 10, 100, 100);*/
	/*fdf_draw_line(g, 3, 27, 46, 7);*/
	fdf_draw_line(g, 46,7,63,30);
	fdf_draw_line(g, 3, 27, 63,27);
	/*fdf_draw_line(g, 10, 100, 100, 10);*/

	/*fdf_vertical_line(g, 10, 10, 10, 100);*/
	/*fdf_vertical_line(g, 100, 10, 100, 100);*/
	/*fdf_horizontal_line(g, 10, 10, 100, 10);*/
	/*fdf_horizontal_line(g, 10, 100, 100, 100);*/
	mlx_put_image_to_window(g->mlx, g->win, g->img, 500, 500);
	mlx_loop(g->mlx);
	// FREE -------------------------------
	mlx_destroy_image(g->mlx, g->img);
	mlx_destroy_window(g->mlx, g->win);
	free(g->mlx);
	fdf_print_map(g);
	return ;
}
