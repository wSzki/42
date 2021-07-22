
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
void fdf_sharp_angle_bresenham_line(t_global *g, int x0, int y0, int x1, int y1, int angle)
{
	int x;
	int y;
	int p;
	int i = 0;
	int max;

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
		if (angle >= 135 && angle < 315)
			x0--;
		else
			x0++;
		i++;
	}
}

void fdf_wide_angle_bresenham_line(t_global *g, int x0, int y0, int x1, int y1, int angle)
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
		if (angle >= 135 && angle < 315)
			y0--;
		else
			y0++;
		i++;
	}
}

////////////////////////////////////////////////////////////////////////////////////////
//
void fdf_vector_draw(t_global *g)
{

	if ((g->x0 - g->x1) == 0)
		fdf_vertical_line(g, g->x0, g->y0, g->x1, g->y1);
	else if (abs(g->x1 - g->x0) < abs(g->y1 - g->y0))
		fdf_wide_angle_bresenham_line(g, g->x0, g->y0, g->x1, g->y1, g->degrees);
	else
		fdf_sharp_angle_bresenham_line(g, g->x0, g->y0, g->x1, g->y1, g->degrees);
}

//
/////////////////////////////////////////////////////////////////////////////////////////


static void	fdf_vector_reset(t_global *g)
{
	g->x0 = 0;
	g->y0 = 0;
	g->x1 = 0;
	g->y1 = 0;
	g->magnitude = 0;
	g->radian = 0;
	g->degrees = 0;
}

static void fdf_vector_generate(t_global *g, int x0, int y0, int size)
{
	g->magnitude =  sqrt(size * size);
	g->x0 = x0;
	g->y0 = y0;
	g->x1 = round(g->magnitude * cosf(0) + x0);
	g->y1 = round(g->magnitude * sinf(0) + y0);
}

void fdf_vector_rotate(t_global *g, int angle)
{
	g->degrees = angle;
	g->radian = angle * (M_PI / 180);
	g->x1 = round(g->magnitude * cosf(g->radian) + g->x0);
	g->y1 = round(g->magnitude * sinf(g->radian) + g->y0);
}

void fdf_vector_color(t_global *g, int color)
{
	g->color = color;
}

void fdf_vector_print_data(t_global *g)
{

	printf("x0 %d\n", g->x0);
	printf("y0 %d\n", g->y0);
	printf("x1 %d\n", g->x1);
	printf("y1 %d\n", g->y1);
	printf("magnitude %f\n", g->magnitude);
	printf("radian %f\n",g->radian);
	printf("degrees %d\n", g->degrees);
	printf("color %d\n", g->color);
}
void	fdf_mlx_start(t_global *g)
{

	///////////////////////////////////////////
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 500, 500, "window");
	g->img = mlx_new_image(g->mlx, 500, 500);
	/*data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);*/
	///////////////////////////////////////////
	int i = 0;
	//
	while (i < 360)
	{
		fdf_vector_reset(g);
		fdf_vector_generate(g, 250, 250, 205);
		fdf_vector_rotate(g, i++);
		fdf_vector_draw(g);
	}

	/*fdf_draw_line3(g, 250, 250, 205, 90);*/
	/*fdf_draw_line3(g, 250, 250, 205, 135);*/
	/*fdf_draw_line3(g, 250, 250, 205, 180);*/
	/*fdf_draw_line3(g, 250, 250, 205, 225);*/
	/*fdf_draw_line3(g, 250, 250, 205, 270);*/
	/*fdf_draw_line3(g, 250, 250, 205, 315);*/
	/*///////////////////////////////////////////*/

	/*int i = 0;*/
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
	/*i = 0;*/
	/*while (i < 360)*/
	/*{*/
	/*fdf_draw_line3(g, 250, 250, 155, i);*/
	/*i++;*/
	/*usleep(10000);*/
	/*}*/

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
