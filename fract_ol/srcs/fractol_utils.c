
#include "../includes/fractol.h"

void	fractol_putstr(const char *s)
{
	if (s)
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
}

int		fractol_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void fractol_input_check(int ac, char **av)
{
	if (ac != 2)
	{
		fractol_putstr("Error\nType of fractal required as argument");
		exit(1);
	}
	if (!((fractol_strcmp(av[1], "julia") == 0 || fractol_strcmp(av[1], "mandelbrot") == 0)))
	{
		fractol_putstr("Error\nInvalid parameter, must be 'julia' or 'mandelbrot'");
		exit(1);
	}
}
