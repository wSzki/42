/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_path_north.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:27:23 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/15 20:44:14 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_line_path_north(char **line_split, t_input_data *input_data)
{
	if (ft_strcmp(line_split[0], "NO") == 0)
	{
		if (*(input_data->north_texture_path) == '\0')
			input_data->north_texture_path = line_split[1];
	}

}
