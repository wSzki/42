/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:58:29 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/21 01:09:10 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void	fetch_arguments(char *line, t_global *g)
{
	int		i;
	int		arg_count;
	char	**line_split;

	i = -1;
	arg_count = 0;
	line_split = ft_split(line, ' ');
	arg_count = number_of_args(line_split);
	if (arg_count == 1)
		append_error(g, line_split[0], " : not enough arguments\n");
	if (arg_count > 3)
		append_error(g, line_split[0], " : too many arguments\n");
	if (arg_count == 3)
		parse_line_resolution(line_split, g);
	if (arg_count == 2)
		parse_line_paths(line_split, g);
	while (line_split[++i])
		free(line_split[i]);
	free(line_split);
}

static void		check_parameter_count_and_map(t_global *g)
{
	if (g->valid_parameter_count != 8)
		append_error(g, "", "Not enough valid parameters\n");
	if (*(g->map_data) == NULL)
		append_error(g, "", "No map found\n");
}

void			parse_input(t_global *g)
{
	int		fd;
	char	*line;

	fd = open("./assets/map.cub", O_RDONLY);
	if (fd < 0)
	{
		append_error(g, "", "Cannot open map\n");
		return ;
	}
	while ((get_next_line(&line, fd) > 0))
	{
		if (detect_map_line(line))
		{
			parse_map(line, fd, g);
			break ;
		}
		fetch_arguments(line, g);
		free(line);
		line = NULL;
	}
	check_parameter_count_and_map(g);
	free(line);
	line = NULL;
	close(fd);
}
