/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarter_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:29:00 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/08 17:58:29 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	print_all(t_global *g);
static int	find_closest_chunk(t_global *g, long first_median, long second_median)
{
	int i;

	i = 0;
	while (i < A_SIZE / 2)
	{
		if (A_DATA[i] > first_median && A_DATA[i] <= second_median)
			return (0);
		i++;
	}
	return (1);
}

void	quarter_sort(t_global *g, long first_median, long second_median, int offset)
{
	int i;
	int direction;


	i = -1;
	while (++i < A_SIZE / 2)
		if (A_DATA[i] > first_median && A_DATA[i] <= second_median)
			direction = 0;
	direction = 0;
	i = A_SIZE - offset;
	while (A_SIZE - offset > (i * 3) / 4)
	{
		direction = find_closest_chunk(g, first_median, second_median);
		if (A_DATA[0] > first_median && A_DATA[0] <= second_median)
			px(g, B_ID);
		else if (direction == 0)
			rx(g, A_ID);
		else if (direction == 1)
			rrx(g, A_ID);
	}
	while (B_SIZE > 0)
		push_smallest_or_largest(g);
}

