#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_global *g, int x, int y, int color)
{
	char	*dst;

	dst = g->addr + (y * g->line_length + x * (g->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	fractol_print_and_exit(char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
}

int	fractol_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	fractol_isfloat(char *str)
{
	int	i;
	int	point_count;

	i = 0;
	point_count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 0)
		return (0);
	while (str[i] != 0)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return (0);
		if (str[i] == '.')
			point_count++;
		i++;
	}
	if (point_count > 1)
		return (0);
	return (1);
}

void	fractol_input_check(int ac, char **av)
{
	if (ac == 1)
		fractol_print_and_exit("No input parameter given");
	if (fractol_strcmp(av[1], "mandelbrot") == 0)
	{
		if (ac != 2)
			fractol_print_and_exit("\
					'mandelbrot' does not take additional parameters");
	}
	else if (fractol_strcmp(av[1], "julia") == 0)
	{
		if (ac != 2 && ac != 4)
			fractol_print_and_exit("\
					'julia' takes 0 or 2 additional parameters : \
					Cr & Ci (floats)");
	}
	else
		fractol_print_and_exit("Invalid fractal name");
}
