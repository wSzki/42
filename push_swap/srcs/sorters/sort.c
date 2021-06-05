/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:48:51 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/05 14:14:50 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	print_all(t_global *g);

static void find_median(t_tab *tab, int *median, int min_value, int max_value)
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
			if (tab->data[j] < target && tab->data[j] > min_value)
				count--;
			if (tab->data[j] > target && tab->data[j] < max_value)
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
	int median_a;
	int median_b;
	int median_c;

	check_simple_cases(g);
	find_median(A, &median_a, find_smallest(A), find_largest(A));
	find_median(A, &median_b, find_smallest(A), median_a);
	find_median(A, &median_c, median_a, find_largest(A));

	i = A_SIZE;

	while (A_SIZE > i / 4 * 3)
	{
		if (A_DATA[0] > median_c)
			px(g, B_ID);
		else
			rx(g, A_ID);
	}
	while (B_SIZE > 0)
		push_smallest_or_largest(g);


	while (A_SIZE > i / 4 * 3)
	{
		if (A_DATA[0] > median_a && A_DATA[0] <= median_c)
			px(g, B_ID);
		else
			rx(g, A_ID);
	}
	while (B_SIZE > 0)
		push_smallest_or_largest(g);

	while (A_SIZE > i / 4 * 3)
	{
		if (A_DATA[0] <= median_a && A_DATA[0] > median_b)
			px(g, B_ID);
		else
			rx(g, A_ID);
	}
	while (B_SIZE > 0)
		push_smallest_or_largest(g);

	while (A_SIZE > i / 4 * 3)
	{
		if (A_DATA[0] <= median_b)
			px(g, B_ID);
		else
			rx(g, A_ID);
	}
	while (B_SIZE > 0)
		push_smallest_or_largest(g);




	/*while (A_SIZE > i / 2)*/
	/*{*/
		/*if (A_DATA[0] > median_a)*/
			/*px(g, B_ID);*/
		/*else*/
			/*rx(g, A_ID);*/
	/*}*/
	/*while (B_SIZE > 0)*/
		/*push_smallest_or_largest(g);*/
	scroll_to(g, A, find_smallest(A));
	print_all(g);
}
