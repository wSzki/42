
#include "../includes/fdf.h"


/*void fdf_draw_square(t_global *g, int x0, int y0, int size)*/
/*{*/
/*fdf_draw_line(g, x0, y0, x0 + size, y0 + 20);*/
/*fdf_draw_line(g, x0 + size, y0 + size, x0 + size, y0);*/
/*fdf_draw_line(g, x0, y0 + size, x0 + size, y0 + size);*/
/*fdf_draw_line(g, x0, y0, x0, y0 + size);*/



/*}*/

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
		mlx_pixel_put(g->mlx, g->win, x0, y0, 0x00FABd2f);
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

void	fdf_draw_line2(t_global *g, int x0, int y0, int x1, int y1, float radian)
{
	int tmp;
	int x;
	int y;
	float m;
	if (x0 > x1)
	{
		tmp = x0;
		x0 = x1;
		x1 = tmp;
		tmp = y0;
		y0 = y1;
		y1 = tmp;
	}
	x = x1 - x0;
	y = y1 - y0;
	m = sqrt(x * x + y * y);
	x1 = m * cosf(radian);
	y1 = m * sinf(radian);

	if (x0 > x1)
	{
		tmp = x0;
		x0 = x1;
		x1 = tmp;
		tmp = y0;
		y0 = y1;
		y1 = tmp;
	}
	printf("%d\n", y1);
	printf("%d\n", x1);

	if (abs(x1 - x0) < abs(y1 - y0))
	{
		fdf_wide_angle_bresenham_line(g, x0, y0, x1, y1);
	}
	else
	{
		fdf_sharp_angle_bresenham_line(g, x0, y0, x1, y1);
	}
}
////////////////////////////////////////////////////////////////////////////////////////
//
void fdf_draw_line3(t_global *g, int x0, int y0, int size, float angle)
{
	int x1;
	int y1;
	int tmp;
	float magnitude;
	float radian;

	magnitude = sqrt(size * size);
	radian = angle * (M_PI / 180);
	x1 = magnitude * cos(radian) + x0;
	y1 = magnitude * sin(radian) + y0;
	if (x0 > x1)
	{
		tmp = x0;
		x0 = x1;
		x1 = tmp;
		tmp = y0;
		y0 = y1;
		y1 = tmp;
	}
	if (abs(x1 - x0) < abs(y1 - y0))
		fdf_wide_angle_bresenham_line(g, x0, y0, x1, y1);
	else
		fdf_sharp_angle_bresenham_line(g, x0, y0, x1, y1);
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

	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 500, 500, "window");
	g->img = mlx_new_image(g->mlx, 500, 500);
	/*data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);*/


	fdf_reset_vector(g);



	int i = 0;
	while (i < 360)
	{
		fdf_draw_line3(g, 250, 250, 305, i);
		i++;
		usleep(1000);

	}

	/*fdf_draw_line2(g, 100, 100, 400, 100, M_PI / 5);*/



	mlx_put_image_to_window(g->mlx, g->win, g->img, 500, 500);
	mlx_loop(g->mlx);

	// FREE -------------------------------
	mlx_destroy_image(g->mlx, g->img);
	mlx_destroy_window(g->mlx, g->win);
	free(g->mlx);
	fdf_print_map(g);
	return ;
}
