/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:56:00 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/20 17:45:24 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	fdf_init_int_map(t_global *g)
{
	int	i;

	i = 0;
	g->map = malloc(sizeof(int **) * (g->y + 1));
	if (!g->map)
	{
		fdf_free_all(g);
		p_exit("ERROR: g->map malloc failed");
	}
	g->map[g->y] = 0;
	while (i < g->y)
	{
		g->map[i] = NULL;
		g->map[i] = malloc(sizeof(int *) * (g->x + 1));
		if (!(g->map[i]))
		{
			fdf_free_all(g);
			p_exit("ERROR: g->map[i] malloc failed");
		}
		g->map[i][g->x] = 0;
		i++;
	}
}

static void	fdf_split_and_convert(t_global *g)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (g->tmp_map[i])
	{
		j = 0;
		split = ft_split(g->tmp_map[i], ' ');
		while (split[j])
		{
			g->map[i][j] = fdf_atoi_overflow(g, split[j]);
			j++;
		}
		j = 0;
		while (split[j])
		{
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
}

void	fdf_init_map(t_global *g)
{
	fdf_map_checks(g);
	fdf_init_int_map(g);
	fdf_split_and_convert(g);
}
