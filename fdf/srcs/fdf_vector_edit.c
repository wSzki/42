#include "../includes/fdf.h"

void	fdf_vector_reset(t_global *g)
{
	g->x0 = 0;
	g->y0 = 0;
	g->x1 = 0;
	g->y1 = 0;
	g->magnitude = 0;
	g->radian = 0;
	g->degrees = 0;
	g->color = 0x00FFFFFF;
}

void	fdf_vector_generate(t_global *g, int x0, int y0, int size)
{
	g->magnitude = sqrt(size * size);
	g->x0 = x0;
	g->y0 = y0;
	g->x1 = round(g->magnitude * cosf(g->degrees) + x0);
	g->y1 = round(g->magnitude * sinf(g->degrees) + y0);
}

void	fdf_vector_rotate(t_global *g, int angle)
{
	g->degrees = angle;
	g->radian = angle * (M_PI / 180);
	g->x1 = round(g->magnitude * cosf(g->radian) + g->x0);
	g->y1 = round(g->magnitude * sinf(g->radian) + g->y0);
}

void	fdf_vector_color(t_global *g, unsigned int color)
{
	g->color = color;
}
