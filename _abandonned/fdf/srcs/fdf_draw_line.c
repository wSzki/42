#include "../includes/fdf.h"

static void	fdf_vertical_line(t_global *g, int x0, int y0, int x1, int y1)
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
		mlx_pixel_put(g->mlx, g->win, x0, y0, g->color);
		y0++;
	}
}

static void	fdf_horizontal_line(t_global *g, int x0, int y0, int x1, int y1)
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
		mlx_pixel_put(g->mlx, g->win, x0, y0, g->color);
		x0++;
	}
}

static void fdf_sharp_angle_bresenham_line(t_global *g, int x0, int y0, int x1, int y1)
{
	int x;
	int y;
	int p;
	int i = 0;

	x = abs(x1 - x0);
	y = abs(y1 - y0);
	p = 2 * x - y;
	while (x0 < x1)
	{
		mlx_pixel_put(g->mlx, g->win, x0, y0, g->color);
		if (p >= 0)
		{
			p += (2 * y) - (2 * x);
			if (y0 < y1)
				y0++;
			if (y0 > y1)
				y0--;
		}
		else
			p += 2 * y;
		x0++;
		i++;
	}
}

static void fdf_wide_angle_bresenham_line(t_global *g, int x0, int y0, int x1, int y1)
{
	int x;
	int y;
	int p;
	int i = 0;

	x = abs(x1 - x0);
	y = abs(y1 - y0);
	p = 2 * y - x;

	while (y0 < y1)
	{
		mlx_pixel_put(g->mlx, g->win, x0, y0, g->color);
		if (p >= 0)
		{
			p += (2 * x) - (2 * y);
			if (y0 < y1)
				x0++;
			if (y0 > y1)
				x0--;
		}
		else
			p += 2 * x;
		y0++;
		i++;
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
		mlx_pixel_put(g->mlx, g->win, x0, y0, g->color);
	else if ((x0 - x1) == 0)
		fdf_vertical_line(g, x0, y0, x1, y1);
	else if ((y0 - y1) == 0)
		fdf_horizontal_line(g, x0, y0, x1, y1);
	else if (abs(x1 - x0) < abs(y1 - y0))
		fdf_wide_angle_bresenham_line(g, x0, y0, x1, y1);
	else
		fdf_sharp_angle_bresenham_line(g, x0, y0, x1, y1);
}
