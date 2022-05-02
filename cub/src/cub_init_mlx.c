/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:27:50 by wszurkow          #+#    #+#             */
/*   Updated: 2022/03/16 17:38:49 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

/* Filling Background upper and lower half */
static void	cub_init_background(t_global *g)
{
	int	w;
	int	h;

	h = 0;
	while (h++ < g->w.h)
	{
		w = 0;
		while (w++ < g->w.w)
		{
			if (h < g->w.h / 2)
				cub_put_pixel(&g->x.background, w, h, g->d.c);
			else
				cub_put_pixel(&g->x.background, w, h, g->d.f);
		}
	}
}

/* Coloring minimap  component images : wall, floor, player */
static void	cub_init_minimap_blocks(t_global *g, int w, int h)
{
	w = 1;
	while (w < g->mm.block_size)
	{
		h = 1;
		while (h < g->mm.block_size)
		{
			cub_put_pixel(&g->x.mm_floor, w, h, g->mm.floor_color);
			cub_put_pixel(&g->x.mm_wall, w, h, g->mm.wall_color);
			h++;
		}
		w++;
	}
	w = 0;
	while (w < g->mm.player_size)
	{
		h = 0;
		while (h < g->mm.player_size)
		{
			cub_put_pixel(&g->x.mm_player, w, h, g->mm.player_color);
			h++;
		}
		w++;
	}
}

static void	cub_init_minimap_data(t_global *g)
{
	int	width_or_height;
	int	cols_or_rows;

	width_or_height = g->w.w;
	cols_or_rows = g->m.cols;
	if (g->m.rows > g->m.cols)
	{
		width_or_height = g->w.h;
		cols_or_rows = g->m.rows;
	}
	g->mm.block_size = width_or_height / cols_or_rows;
	g->mm.player_size = g->mm.block_size / 4;
	g->mm.floor_color = MM_FLOOR_COLOR;
	g->mm.wall_color = MM_WALL_COLOR;
	g->mm.player_color = MM_PLAYER_COLOR;
}

/* Generating the minimap, and positioning the player */
static void	cub_init_minimap(t_global *g, int h, int w)
{
	int	size;

	size = g->mm.block_size;
	while (g->m.map[h])
	{
		w = 0;
		while (g->m.map[h][w])
		{
			if (g->m.map[h][w] == '1')
				cub_img_join(&g->x.minimap, &g->x.mm_wall, w * size, h * size);
			else
			{
				if (g->p.x == 0 && ft_is_in_c(g->m.map[h][w], "NSEW"))
				{
					g->p.x = w * size + size / 2;
					g->p.y = h * size + size / 2;
					cub_init_angle(g, g->m.map[h][w]);
				}
				cub_img_join(&g->x.minimap, &g->x.mm_floor, w * size, h * size);
			}
			w++;
		}
		h++;
	}
}

void	cub_init_mlx(t_global **global)
{
	t_global	*g;

	g = *global;
	g->x.mlx = mlx_init();
	if (g->x.mlx == NULL)
		cub_error_str(g, MERR_MLX);
	g->x.win = mlx_new_window(g->x.mlx, g->w.w, g->w.h, WINDOW_NAME);
	if (g->x.win == NULL)
		cub_error_str(g, MERR_MLX);
	cub_init_img(g, &g->x.buffer, g->w.w, g->w.h);
	cub_init_img(g, &g->x.background, g->w.w, g->w.h);
	cub_init_background(g);
	cub_init_minimap_data(g);
	cub_init_img(g, &g->x.minimap, g->w.w, g->w.h);
	cub_init_img(g, &g->x.mm_wall, g->mm.block_size, g->mm.block_size);
	cub_init_img(g, &g->x.mm_floor, g->mm.block_size, g->mm.block_size);
	cub_init_img(g, &g->x.mm_player, g->mm.player_size, g->mm.player_size);
	cub_init_minimap_blocks(g, 0, 0);
	cub_init_minimap(g, 0, 0);
}
