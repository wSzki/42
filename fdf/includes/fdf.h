/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:20:43 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/19 19:02:21 by wszurkow         ###   ########.fr       */
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
}				t_global;

void fdf_print_map(t_global *g);
void fdf_open(t_global *g, int ac, const char *path);
char	**fdf_dual_realloc(char **double_ptr, char *line);
void	fdf_map_checks(t_global *g);
t_global *fdf_init(void);
void	fdf_free_all(t_global *g);

#endif
