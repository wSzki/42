/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_empty_ret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:13:09 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 20:37:58 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int	empty_ret(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("./get_next_line/empty", O_RDONLY);
	ret = get_next_line(fd, &line);
	close(fd);
	if (ret != 0)
		return (-1);
	return (0);
}
