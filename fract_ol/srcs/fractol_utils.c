
#include "../includes/fractol.h"

int		fractol_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void fractol_input_check(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\n%s", "Type of fractal required as argument");
		exit(1);
	}
	if (!((fractol_strcmp(av[1], "julia") == 0 || fractol_strcmp(av[1], "mandelbrot") == 0)))
	{
		printf("Error\n%s", "Invalid parameter, must be 'julia' or 'mandelbrot'");
		exit(1);
	}
}

void	my_mlx_pixel_put(t_global *g, int x, int y, int color)
{
	char	*dst;

	dst = g->addr + (y * g->line_length + x * (g->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
