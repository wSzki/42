/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:58:29 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/18 20:02:12 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void	fetch_arguments(char *line, t_global *g)
{
	/*int i;*/
	int		arg_count;
	char	**line_split;

	/*i = -1;*/
	arg_count = 0;
	line_split = ft_split(line, ' ');
	arg_count = number_of_args(line_split);
	if (arg_count == 1)
		g->error = dual_realloc(g->error, " too few arguments");
	if (arg_count > 3)
		g->error = dual_realloc(g->error, " too many arguments");
	if (arg_count == 3)
		parse_line_resolution(line_split, g);
	if (arg_count == 2)
		parse_line_paths(line_split, g);
	/*while (line_split[++i])*/
	/*free(line_split[i]);*/
	free(line_split);
}

static	int		open_fd(char *str, t_global *g)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		g->error = dual_realloc(g->error, ".cub file not found");
	return (fd);
}

void			parse_input(t_global *g)
{
	int		fd;
	char	*line;

	fd = open_fd("./assets/map.cub", g);
	while ((get_next_line(&line, fd) > 0))
	{
		if (detect_map_line(line))
		{
			parse_map(line, fd, g);
			break ;
		}
		fetch_arguments(line, g);
		free(line);
	}
	close(fd);
}
