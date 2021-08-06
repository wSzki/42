/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:20:43 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/06 23:51:26 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGHT 500
# define WIDTH 500
# define X_BORDER -1.5
# define Y_BORDER 1.5
# define RELATIVE_SIZE 3

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "../ext/minilibx-linux/mlx.h"

typedef struct s_global
{
	void *mlx;
	void *win;
	void *img;
	int *color;
	char fractal_type;

}				t_global;

int		fractol_strcmp(char *s1, char *s2);
void	fractol_putstr(const char *s);

void fractol_input_check(int ac, char **av);
t_global *fractol_init(t_global *g, char *type);
void	fractol_run(t_global *g);


#endif
