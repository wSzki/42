#include "../includes/fractol.h"

static void fractol_zoom(t_global *g, char direction)
{
	if (direction == '+')
	{
		g->x_total *= 0.9;
		g->y_total *= 0.9;
		g->x_origin = -0.55 - (g->x_total * 0.5);
		g->y_origin = -0.00 + (g->y_total * 0.5);
		fractol_run(g);
		mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	}
	if (direction == '-')
	{
		g->x_total *= 1.1;
		g->y_total *= 1.1;
		g->x_origin = 0 - (g->x_total * 0.5);
		g->y_origin = 0 + (g->y_total * 0.5);
		fractol_run(g);
		mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	}
}

int	fractol_get_key_event(int key, t_global *g)
{

	if (key == 32)
		fractol_zoom(g, '+');
	if (key == ECHAP)
		free_all_and_exit(g);
	return (1);
}

int	fractol_get_scroll_event(int key, int x, int y, t_global *g)
{
	(void)x;
	(void)y;
	if (key == WHEEL_UP)
		fractol_zoom(g, '+');
	if (key == WHEEL_DOWN)
		fractol_zoom(g, '-');
	return (1);
}
void	fractol_set_hooks(t_global *g)
{
	mlx_key_hook(g->win, fractol_get_key_event, g);
	mlx_mouse_hook(g->win, fractol_get_scroll_event, g);
}
