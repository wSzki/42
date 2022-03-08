/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_unicode_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:19:16 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 19:40:43 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int	unicode_test(void)
{
	int		fd;
	int		ret;
	char	*line;
	t_buf	buf;

	buf.len = 0;
	ft_bzero(buf.buf, BUFFER_SIZE);
	fd = open("./get_next_line/to_read3", O_RDONLY);
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		buf_write(&buf, fd, line, ft_strlen(line));
		ret = get_next_line(fd, &line);
	}
	close(fd);
	if (ft_strcmp(buf.buf, "♡"))
		return (-1);
	return (0);
}
