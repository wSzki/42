/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarter_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:29:00 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/08 19:44:52 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static int	find_closest_chunk(t_global *g, long smallest, long largest)
{
	int	i;

	i = 0;
	while (i < A_SIZE / 2)
	{
		if (A_DATA[i] > smallest && A_DATA[i] <= largest)
			return (0);
		i++;
	}
	return (1);
}

void	quarter_sort(t_global *g, long smallest, long largest, int offset)
{
	int	i;
	int	direction;

	i = -1;
	while (++i < A_SIZE / 2)
		if (A_DATA[i] > smallest && A_DATA[i] <= largest)
			direction = 0;
	direction = 0;
	i = A_SIZE - offset;
	while (A_SIZE - offset > (i * 3) / 4)
	{
		direction = find_closest_chunk(g, smallest, largest);
		if (A_DATA[0] > smallest && A_DATA[0] <= largest)
			px(g, B_ID);
		else if (direction == 0)
			rx(g, A_ID);
		else if (direction == 1)
			rrx(g, A_ID);
	}
	while (B_SIZE > 0)
		push_smallest_or_largest(g);
}
