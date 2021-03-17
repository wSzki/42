/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:42:55 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/17 18:25:22 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"
#include "../libft/libft.h"


///////////////////////////

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

///////////////////////////

typedef struct s_map
{
	char **map_data;
	char **map_cells;
	int cell_count;
	int number_rows;
	int number_columns;
	int largest_row;

}				t_map;

typedef struct s_window
{
	int x_resolution;
	int y_resolution;
}			t_window;

typedef struct s_map_textures
{
	char *north_texture_path;
	char *south_texture_path;
	char *east_texture_path;
	char *west_texture_path;
	char *sprite_texture_path;
	char *floor_color;
	char *ceiling_color;
}				t_map_textures;

typedef struct s_global
{
	int error;
	int valid_parameter_count;
	t_data *data;
	t_map *map;
	t_window *window;
	t_map_textures *map_textures;
}				t_global;

void	cub3d_entrypoint(void);
int get_next_line(char **line, int fd);

// UTILS
int		is_in_charset(char c, char *charset);
int		ft_is_number(char *str);
int		number_of_args(char **line);

// PARSERS
void	init_struct(t_global *g);
void	parse_line_resolution(char **line, t_global *g);
void	parse_line_paths(char **line, t_global *g);


#endif
