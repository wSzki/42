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

static void fdf_sharp_angle_bresenham_line(t_global *g, int x0, int y0, int x1, int y1, int angle)
{
	int x;
	int y;
	int p;
	int i;
	int max;

	i = 0;
	max = abs(x0 - x1);
	x = abs(x1 - x0);
	y = abs(y1 - y0);
	p = 2 * x - y;
	while (i < max)
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
		if (angle >= 135 && angle < 315)
			x0--;
		else
			x0++;
		i++;
	}
}

static void fdf_wide_angle_bresenham_line(t_global *g, int x0, int y0, int x1, int y1, int angle)
{
	int x;
	int y;
	int p;
	int i;
	int max;

	i = 0;
	max = abs(y0 - y1);
	x = abs(x1 - x0);
	y = abs(y1 - y0);
	p = 2 * y - x;
	while (i < max)
	{
		mlx_pixel_put(g->mlx, g->win, x0, y0, g->color);
		if (p >= 0)
		{
			p += (2 * x) - (2 * y);
			if (x0 < x1)
				x0++;
			if (x0 > x1)
				x0--;
		}
		else
			p += 2 * x;
		if (angle >= 135 && angle < 315)
			y0--;
		else
			y0++;
		i++;
	}
}

void fdf_vector_draw(t_global *g)
{
	if ((g->x0 - g->x1) == 0)
		fdf_vertical_line(g, g->x0, g->y0, g->x1, g->y1);
	else if (abs(g->x1 - g->x0) < abs(g->y1 - g->y0))
		fdf_wide_angle_bresenham_line(g, g->x0, g->y0, g->x1, g->y1, g->degrees);
	else
		fdf_sharp_angle_bresenham_line(g, g->x0, g->y0, g->x1, g->y1, g->degrees);
	g->x0 = g->x1;
	g->y0 = g->y1;
}

/*void fdf_vector_draw(t_global *g,int  x_offset, int y_offset)*/
/*{*/
	/*int x0;*/
	/*int y0;*/
	/*int x1;*/
	/*int y1;*/

	/*x0 = g->x0 + x_offset;*/
	/*y0 = g->y0 + y_offset;*/
	/*x1 = g->x1 + x_offset;*/
	/*y1 = g->y1 + y_offset;*/
	/*if ((x0 - x1) == 0)*/
		/*fdf_vertical_line(g, x0, y0, x1, y1);*/
	/*else if (abs(x1 - x0) < abs(y1 - y0))*/
		/*fdf_wide_angle_bresenham_line(g, x0, y0, x1, y1, g->degrees);*/
	/*else*/
		/*fdf_sharp_angle_bresenham_line(g, x0, y0, x1, y1, g->degrees);*/
/*}*/

