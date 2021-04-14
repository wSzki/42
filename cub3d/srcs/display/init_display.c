/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:49:11 by wszurkow          #+#    #+#             */
/*   Updated: 2021/04/08 20:27:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void init_mlx_struct(t_global *g)
{
	g->paint = malloc(sizeof(t_paint));
	g->paint->x_offset = 0;
	g->paint->y_offset = 0;
	g->paint->color = 0;
	g->data = malloc(sizeof(t_data));
	g->minimap = malloc(sizeof(t_data));
	g->player = malloc(sizeof(t_data));
	g->buffer = malloc(sizeof(t_data));
	if (!(g->data))
		return ;
	if (!(g->minimap))
		return ;
	if (!(g->player))
		return ;
}

void	init_mlx(t_global *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(\
			g->mlx, \
			g->window->x_resolution, \
			g->window->y_resolution, \
			"name");
}

void	init_image(t_global *g, t_data *data)
{
	data->img = mlx_new_image(\
			g->mlx, \
			g->window->x_resolution , \
			g->window->y_resolution);

	data->addr = mlx_get_data_addr(\
			data->img, \
			&(data->bits_per_pixel), \
			&(data->line_length), \
			&(data->endian));
}
