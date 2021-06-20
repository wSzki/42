/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:20:43 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/20 14:02:29 by wszurkow         ###   ########.fr       */
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

t_global	*fdf_init(void);
void	fdf_init_map(t_global *g);
void	fdf_print_map(t_global *g);
void	fdf_open(t_global *g, int ac, const char *path);
void	fdf_map_checks(t_global *g);
void	fdf_free_all(t_global *g);
int	fdf_atoi_overflow(t_global *g, const char *str);
char	**fdf_dual_realloc(char **double_ptr, char *line);

#endif
