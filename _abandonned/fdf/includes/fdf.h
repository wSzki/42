/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:20:43 by wszurkow          #+#    #+#             */
/*   Updated: 2021/07/22 14:31:27 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "../externals/ft_minilibx/mlx.h"
# include "../externals/libft/libft.h"
# include "../externals/ft_printf/includes/ft_printf.h"

typedef struct s_global
{
	char **tmp_map;
	int **map;
	int x;
	int y;

	void *mlx;
	void *win;
	void *img;
	int x_res;
	int y_res;

	int x0;
	int y0;
	int x1;
	int y1;
	int degrees;
	float magnitude;
	float radian;
	unsigned int color;
}				t_global;

typedef struct s_line
{
	int x_start;
	int y_start;
	int x_end;
	int y_end;
}				t_line;

t_global	*fdf_init(void);
void	fdf_mlx_start(t_global *g);
void	fdf_init_map(t_global *g);
void	fdf_print_map(t_global *g);
void	fdf_open(t_global *g, int ac, const char *path);
void	fdf_map_checks(t_global *g);
void	fdf_free_all(t_global *g);
int	fdf_atoi_overflow(t_global *g, const char *str);
char	**fdf_dual_realloc(char **double_ptr, char *line);
void	fdf_draw_line(t_global *g, int x0, int y0, int x1, int y1);


void fdf_vector_reset(t_global *g);
void fdf_vector_generate(t_global *g, int x0, int y0, int size);
void fdf_vector_rotate(t_global *g, int angle);
void fdf_vector_color(t_global *g, unsigned int color);
void fdf_vector_draw(t_global *g);

#endif
