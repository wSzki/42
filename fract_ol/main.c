#include "./includes/fractol.h"

int main (int ac, char **av)
{
	t_global *g;

	g = NULL;
	fractol_input_check(ac, av);
	g = fractol_init(g, av[1]);
	fractol_run(g);
	mlx_loop(g->mlx);
	///////////////////////////
}
