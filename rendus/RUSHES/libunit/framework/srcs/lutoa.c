/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lutoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:37:20 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 17:20:09 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

char	*ft_lutoa(t_ulong n)
{
	char	*res;
	int		res_size;
	t_ulong	x;

	res_size = 1;
	x = n;
	while (x / 10)
	{
		res_size++;
		x /= 10;
	}
	res = (char *)malloc(res_size + 1);
	if (!res)
		return (NULL);
	res[res_size] = '\0';
	while (res_size--)
	{
		res[res_size] = '0' + n % 10;
		n /= 10;
	}
	return (res);
}
