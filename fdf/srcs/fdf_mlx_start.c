
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
		mlx_pixel_put(g->mlx, g->win, x0, y0, 0x00FFFFFF);
		y0++;
	}
}
void fdf_sharp_angle_bresenham_line(t_global *g, int x0, int y0, int x1, int y1)
{
	int x;
	int y;
	int p;
	int i = 0;
	int max;

	i = 0;
	max = abs(x0 - x1);
	x = abs(x1 - x0);
	y = abs(y1 - y0);
	p = 2 * x - y;
	while (i < max)
	{
		mlx_pixel_put(g->mlx, g->win, x0, y0, 0x00FFFFFF);
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

void fdf_sharp_angle_bresenham_line2(t_global *g, int x0, int y0, int x1, int y1)
{
	int x;
	int y;
	int p;
	int i = 0;
	int max;

	i = 0;
	max = abs(x0 - x1);
	x = abs(x1 - x0);
	y = abs(y1 - y0);
	p = 2 * x - y;
	while (i < max)
	{
		mlx_pixel_put(g->mlx, g->win, x0, y0, 0x00FFFFFF);
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
		x0--;
		i++;
	}
}

void fdf_wide_angle_bresenham_line(t_global *g, int x0, int y0, int x1, int y1)
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
		mlx_pixel_put(g->mlx, g->win, x0, y0, 0x00FABd2f);
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
		y0++;
		i++;
	}
}

void fdf_wide_angle_bresenham_line2(t_global *g, int x0, int y0, int x1, int y1)
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
		mlx_pixel_put(g->mlx, g->win, x0, y0, 0x00FABd2f);
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
		y0--;
		i++;
	}
}
////////////////////////////////////////////////////////////////////////////////////////
//
void fdf_draw_line3(t_global *g, int x0, int y0, int size, float angle)
{
	int x1;
	int y1;
	/*int tmp;*/
	float magnitude;
	float radian;

	magnitude = sqrt(size * size);
	radian = angle * (M_PI / 180);
	x1 = round(magnitude * cosf(radian) + x0);
	y1 = round(magnitude * sinf(radian) + y0);
	if ((x0 - x1) == 0)
	{
		fdf_vertical_line(g, x0, y0, x1, y1);
		return ;
	}
	if (abs(x1 - x0) < abs(y1 - y0))
	{
		if (angle > 134 && angle < 315)
			fdf_wide_angle_bresenham_line2(g, x0, y0, x1, y1);
		else
			fdf_wide_angle_bresenham_line(g, x0, y0, x1, y1);
	}
	else
	{
		if (angle > 134 && angle < 315)
			fdf_sharp_angle_bresenham_line2(g, x0, y0, x1, y1);
		else
			fdf_sharp_angle_bresenham_line(g, x0, y0, x1, y1);
		/*printf("%s\n", "----- PING -----2");*/
	}

	printf("%s\n", "-----------");
}

//
/////////////////////////////////////////////////////////////////////////////////////////


static void	fdf_reset_vector(t_global *g)
{
	g->x0 = 0;
	g->y0 = 0;
	g->x1 = 0;
	g->y1 = 0;
	g->magnitude = 0;
	g->radian = 0;
	g->degrees = 0;
}

void	fdf_mlx_start(t_global *g)
{

	///////////////////////////////////////////
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 500, 500, "window");
	g->img = mlx_new_image(g->mlx, 500, 500);
	/*data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);*/
	fdf_reset_vector(g);
	///////////////////////////////////////////
	fdf_draw_line3(g, 250, 250, 205, 0);
	fdf_draw_line3(g, 250, 250, 205, 45);
	fdf_draw_line3(g, 250, 250, 205, 90);
	fdf_draw_line3(g, 250, 250, 205, 135);
	fdf_draw_line3(g, 250, 250, 205, 180);
	fdf_draw_line3(g, 250, 250, 205, 225);
	fdf_draw_line3(g, 250, 250, 205, 270);
	fdf_draw_line3(g, 250, 250, 205, 315);
	///////////////////////////////////////////

	int i = 0;
	/*while (i < 135)*/
	/*{*/
	/*fdf_draw_line3(g, 250, 250, 155, i);*/
	/*i++;*/
	/*usleep(1000);*/
	/*}*/
	/*i = 270;*/
	/*while (i < 360)*/
	/*{*/
	/*fdf_draw_line3(g, 250, 250, 155, i);*/
	/*i++;*/
	/*usleep(1000);*/
	/*}*/
	i = 0;
	while (i < 360)
	{
		fdf_draw_line3(g, 250, 250, 155, i);
		i++;
		usleep(10000);
	}

	///////////////////////////////////////////
	mlx_put_image_to_window(g->mlx, g->win, g->img, 500, 500);
	mlx_loop(g->mlx);
	///////////////////////////////////////////
	// FREE -------------------------------
	mlx_destroy_image(g->mlx, g->img);
	mlx_destroy_window(g->mlx, g->win);
	free(g->mlx);
	fdf_print_map(g);
	return ;
	///////////////////////////////////////////
}
