/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:47:14 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 17:18:49 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

void	buf_write(t_buf *buf, int fd, const void *src, int n)
{
	if (buf->len + n >= BUFFER_SIZE)
	{
		write(fd, buf->buf, buf->len);
		write(fd, src, n);
		buf->len = 0;
	}
	else
	{
		ft_memcpy(buf->buf + buf->len, src, n);
		buf->len += n;
	}
}

static inline int	num_len(t_ulong l)
{
	int		res_size;

	res_size = 1;
	while (l / 10)
	{
		res_size++;
		l /= 10;
	}
	return (res_size);
}

void	buf_write_ulong(t_buf *buf, t_ulong l)
{
	char	*buf_char;
	int		len;
	int		res_size;

	buf_char = buf->buf;
	res_size = num_len(l);
	if (buf->len + res_size >= BUFFER_SIZE)
	{
		write(1, buf->buf, buf->len);
		buf_char = ft_lutoa(l);
		if (buf_char)
			write(1, buf_char, res_size);
		free(buf_char);
		buf->len = 0;
	}
	else
	{
		buf->len += res_size;
		len = buf->len;
		while (res_size--)
		{
			buf_char[--len] = '0' + l % 10;
			l /= 10;
		}
	}
}
