/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_invalid_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:19:16 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 14:38:42 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int	invalid_fd(void)
{
	int		ret;
	char	*line;

	ret = get_next_line(5, &line);
	if (ret != -1)
		return (-1);
	return (0);
}
