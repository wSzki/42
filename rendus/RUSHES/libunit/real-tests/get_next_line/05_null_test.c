/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:13:09 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 19:40:35 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int	null_test(void)
{
	int		fd;
	int		ret;

	fd = open("./get_next_line/to_read", O_RDONLY);
	ret = get_next_line(fd, NULL);
	close(fd);
	if (ret != -1)
		return (-1);
	return (0);
}
