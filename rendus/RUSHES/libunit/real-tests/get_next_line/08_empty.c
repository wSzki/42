/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:13:09 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 20:34:27 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int	empty(void)
{
	int		fd;
	char	*line;

	fd = open("./get_next_line/empty", O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	if (*line)
		return (-1);
	return (0);
}
