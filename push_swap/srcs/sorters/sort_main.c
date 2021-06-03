/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:06:05 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/03 13:26:52 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	print_all(t_global *g);

int	find_smallest(t_tab *tab)
{
	int i;
	int smallest;

	if (tab->size == 0)
		return (0);
	smallest = tab->data[0];
	i = 0;
	while (++i < tab->size)
		if (tab->data[i] < smallest)
			smallest = tab->data[i];
	return (smallest);
}

int	find_largest(t_tab *tab)
{
	int i;
	int largest;

	if (tab->size == 0)
		return (0);
	largest = tab->data[0];
	i = 0;
	while (++i < tab->size)
		if (tab->data[i] > largest)
			largest = tab->data[i];
	return (largest);
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
			ra(g);
		if (steps_to_target < 0)
			rra(g);
	}
	/*}*/
}

int	find_closest(t_global *g)
{
	int i;
	int smallest;
	int largest;
	int smallest_index;
	int largest_index;

	i = 0;
	largest = find_largest(A);
	smallest = find_smallest(A);
	while (i < A_SIZE)
	{
		if (A_DATA[i] == smallest)
			smallest_index = i;
		if (A_DATA[i] == largest)
			largest_index = i;
		i++;
	}
	if (smallest_index > A_SIZE / 2)
		smallest_index = A_SIZE - smallest_index;
	if (largest_index > A_SIZE / 2)
		largest_index = A_SIZE - largest_index;
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
		scroll_to(g, A, find_smallest(A));
		pb(g);
	}
	else
	{
		scroll_to(g, A, find_largest(A));
		pb(g);
		rb(g);
	}
}

int is_sorted(t_global *g)
{
	int i;

	i = 1;
	while (i < A_SIZE)
	{
		if (A_DATA[i - 1] > A_DATA[i])
			return (0);
	}
	return (1);

}
// todo
// compare moves
//
// scroll to position between x >= 0 && y <= 0
// push
//
//
//
void	inject(t_global *g)
{
	if (A_DATA[0] < find_smallest(B))
	{
		pb(g);
		rrb(g);
	}
	if (A_DATA[0] > find_largest(B))
	{
		pb(g);
	}


}



void		sort_main(t_global *g)
{
	check_simple_cases(g);

	while (A_SIZE > 3)
	{
		/*push_smallest_or_largest(g);*/
		inject(g);
	}
	// Sort remaining 3 values in A
	sort_three(g, g->a->data);
	// Refill A from B
	while (B_SIZE > 0)
		pa(g);
	// Rotate to make sure list starts at smallest value
	scroll_to(g, A, find_smallest(A));
	print_all(g);
}
