/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:06:05 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/03 16:05:55 by wszurkow         ###   ########.fr       */
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
}


void b_scroll_to(t_global *g, t_tab *tab, int target_value)
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
/*}*/

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
//

int is_smallest_of_larger(t_global *g, int target)
{
	int i;
	int smallest = target;


	i = -1;
	while (++i < B_SIZE)
		if (B_DATA[i] > A_DATA[0])
			if (smallest > B_DATA[i])
				return (0);
	return (1);
}

int is_largest_of_smallest(t_global *g, int target)
{
	int i;
	int largest = target;


	i = -1;
	while (++i < B_SIZE)
		if (B_DATA[i] < A_DATA[0])
			if (largest < B_DATA[i])
				return (0);
	return (1);
}

//
void	inject(t_global *g)
{
	int i = 0;
	int j = B_SIZE - 1;

	if (A_DATA[0] < find_smallest(B))
	{
		b_scroll_to(g, B, find_largest(B));
		pb(g);
		rrb(g);
		print_all(g);
	}
	else if (A_DATA[0] > find_largest(B))
	{
		b_scroll_to(g, B, find_largest(B));
		pb(g);
	}
	else
	{

		/*while (!(A_DATA[0] < B_DATA[i] && A_DATA[0] > B_DATA[j]) && i < B_SIZE)*/
		while (1)
		{
			if (j == B_SIZE)
				j = 0;

			if (is_smallest_of_larger(g, B_DATA[j]))
				if (is_largest_of_smallest(g, B_DATA[i]))
				{
					pb(g);
					break;
				}
			i++;
			j++;
		}
	}
}



void		sort_main(t_global *g)
{
	check_simple_cases(g);


	pb(g);
	pb(g);
	while (A_SIZE > 0)
	{
		/*push_smallest_or_largest(g);*/
		inject(g);
		print_all(g);
	}
	// Sort remaining 3 values in A
	sort_three(g, g->a->data);
	// Refill A from B
	/*scroll_to(g, B, find_largest(B));*/
	while (B_SIZE > 0)
		pa(g);
	// Rotate to make sure list starts at smallest value
	scroll_to(g, A, find_smallest(A));
	print_all(g);
}