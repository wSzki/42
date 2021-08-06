#include "../includes/fractol.h"

/*
 * Z * (n + 1) = (Z * n) ^ 2 + c;
 * Z * n = (Z * (n - 1)) ^ 2 + c;
 * Z = (Z ^ 2) + c;
 *
 * Z = (a +  b * i)^2 + x + y * i;
 * Z = (a ^ 2 + 2abi + (b * i) ^ 2) + (x + y * i);
 * Z = a ^ 2 + i(2ab) + (i ^ 2) * (b ^ 2) + x + y * i;
 * Z = a ^ 2 + i(2ab) + (-1 * (b ^ 2)) + x + y * i;
 * Z = (a ^ 2 - b ^ 2 + x) + i[(2ab + y)]
 *
 *
 * |Z| = sqrt(a ^2 + b ^2);
 * if Z < 2, within mandelbrot
*/


static int fractol_mandelbrot(t_global *g, float x, float y, int n_max)
{
	int n;
	float tmp;
	float a;
	float b;

	a = 0;
	b = 0;
	n = 0;
	x = X_BORDER + x * RELATIVE_SIZE / WIDTH;
	y = Y_BORDER - y * RELATIVE_SIZE / HEIGHT;
	while (sqrtf(powf(a, 2) + powf(b, 2)) < 2 && n < 1096)
	{
		tmp = a;
		a = powf(a, 2) - powf (b, 2) + x;
		b = (2 * b * tmp) + y;
		n++;
	}
	if (n == n_max)
		return (0x000000);
	return (g->color[n % 32]);
}

void	fractol_run(t_global *g)
{
	float x;
	float y;
	int color;

	color = 0x000000;
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			color = fractol_mandelbrot(g, x, y, 1096);
			mlx_pixel_put(g->mlx, g->win, (int)x, (int)y, color);
		}
	}
}
