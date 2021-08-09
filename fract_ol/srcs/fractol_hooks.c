#include "../includes/fractol.h"

static void fractol_zoom(t_global *g, char direction)
{
	if (direction == '+')
	{
		/*g->x_max *= 0.8;*/
		/*g->y_max *= 0.8;*/
		/*printf("%f\n", g->x_max);*/
		/*g->origin= (g->x_max * 0.5);*/
		/*g->end = (g->y_max * 0.5);*/
		printf("%s\n", "----- PING -----");
		/*fractol_run(g);*/


	}
	if (direction == '-')
	{
		g->x_max *= 1.2;
		g->y_max *= 1.2;
		g->origin= (g->x_max * 0.5);
		g->end = (g->y_max * 0.5);
		fractol_run(g);
	}


}

static int	fractol_get_event(int key, t_global *g)
{

	printf("%d\n", key);
	if (key == ECHAP)
		free_all_and_exit(g);
	if (key == WHEEL_UP)
		fractol_zoom(g, '+');
	if (key == WHEEL_DOWN)
		fractol_zoom(g, '-');
	return (1);
}

void	fractol_set_hooks(t_global *g)
{
	mlx_hook(g->win, 2, 1L << 0, fractol_get_event, g);
	mlx_hook(g->win, 4, 4L << 0, fractol_get_event, g);
	/*mlx_hook(g->win, 33, 1L << 17, free_all_and_exit, g);*/
}
