/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:48:51 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/03 20:16:00 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	print_all(t_global *g);

static int approximatively_equal(int less, int more)
{
	if (less == more - 1)
		return (1);
	if (less == more + 1)
		return (1);
	if (less - 1 == more)
		return (1);
	if (less + 1 == more)
		return (1);
	if (less == more)
		return (1);
	return (0);

}

static void find_median(t_global *g, int *median)
{
	int i;
	int j;
	int less;
	int more;
	int target;

	i = -1;
	while (++i < A_SIZE)
	{
		j = -1;
		less = 0;
		more = 0;
		target = A_DATA[i];
		while (++j < A_SIZE)
		{
			if (A_DATA[j] < target)
				less++;
			if (A_DATA[j] > target)
				more++;
		}
		if (approximatively_equal(less, more))
			*median = A_DATA[i];
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

int	count_steps_to(t_tab *tab, int target)
{
	int i;

	i = 0;
	while (i < tab->size)
	{
		if (tab->data[i] == target)
			break ;
		i++;
	}
	if (i < tab->size / 2)
		return (i);
	return ((tab->size - i) * -1);
}


void scroll_to(t_global *g, t_tab *tab, int target_value)
{
	int steps_to_target;

	/*if (B_SIZE > 1)*/
	/*{*/
	steps_to_target = count_steps_to(tab, target_value);
	while (tab->data[0] != target_value)
	{
		if (steps_to_target > 0)
			rb(g);
		if (steps_to_target < 0)
			rrb(g);
	}
}

void push_smallest_or_largest(t_global *g)
{
	int closest;
	closest = find_closest(g);
	if (closest == 0)
	{
		scroll_to(g, B, find_smallest(B));
		pa(g);
		ra(g);
	}
	else
	{
		scroll_to(g, B, find_largest(B));
		pa(g);
	}
}

void	sort(t_global *g)
{
	int median;

	check_simple_cases(g);
	find_median(g, &median);

	while (A_SIZE > 0)
	{
		if (A_DATA[0] < median)
		{
			pb(g);
		}
		else
		{
			pb(g);
			rb(g);
		}
	}
	while (B_SIZE > 0)
	{
		push_smallest_or_largest(g);
	}
	while (A_DATA[0] != find_smallest(A))
		ra(g);
}
