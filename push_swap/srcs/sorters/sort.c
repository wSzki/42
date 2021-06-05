/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:48:51 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/05 02:29:00 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	print_all(t_global *g);

static void find_median(t_tab *tab, int *median)
{
	int i;
	int j;
	int count;
	int target;

	count = 0;
	i = -1;
	while (++i < tab->size)
	{
		j = -1;
		count = 0;
		target = tab->data[i];
		while (++j < tab->size)
		{
			if (tab->data[j] < target)
				count--;
			if (tab->data[j] > target)
				count++;
		}
		if (count == 0 || count == 1 || count == -1)
		{
			*median = tab->data[i];
			return;
		}
	}
}

int	find_closest(t_global *g)
{
	int i;
	int smallest;
	int largest;
	int smallest_index;
	int largest_index;

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


void push_smallest_or_largest(t_global *g)
{
	int closest;
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

void	sort(t_global *g)
{
	int i;
	int median;

	check_simple_cases(g);
	find_median(A, &median);

	i = A_SIZE;
	while (A_SIZE > i / 2)
	{
		if (A_DATA[0] <= median)
			px(g, B_ID);
		else
			rx(g, A_ID);
	}
	while (B_SIZE > 0)
		push_smallest_or_largest(g);
	while (A_SIZE > i / 2)
	{
		if (A_DATA[0] > median)
			px(g, B_ID);
		else
			rx(g, A_ID);
	}
	while (B_SIZE > 0)
		push_smallest_or_largest(g);
	while (A_DATA[0] != find_smallest(A))
		rx(g, A_ID);
	print_all(g);
}