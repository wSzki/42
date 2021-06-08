/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_smallest_or_largest.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:27:46 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/08 19:40:56 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static int	find_closest(t_global *g)
{
	int	i;
	int	smallest;
	int	largest;
	int	smallest_index;
	int	largest_index;

	i = 0;
	largest = find_largest(B);
	smallest = find_smallest(B);
	while (i < B_SIZE)
	{
		if (B_DATA[i] == smallest)
			smallest_index = i;
		if (B_DATA[i] == largest)
			largest_index = i;
		i++;
	}
	if (smallest_index > B_SIZE / 2)
		smallest_index = B_SIZE - smallest_index;
	if (largest_index > B_SIZE / 2)
		largest_index = B_SIZE - largest_index;
	if (smallest_index < largest_index)
		return (0);
	return (1);
}

void	push_smallest_or_largest(t_global *g)
{
	int	closest;

	closest = find_closest(g);
	if (closest == 0)
	{
		scroll_to(g, B, find_smallest(B));
		px(g, A_ID);
		rx(g, A_ID);
	}
	else
	{
		scroll_to(g, B, find_largest(B));
		px(g, A_ID);
	}
}
