/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:06:05 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/27 21:46:53 by wszurkow         ###   ########.fr       */
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

int	r_or_rr(t_tab *tab, int target)
{
	int i;

	i = -1;
	while (++i < tab->size / 2)
		if (tab->data[i] == target)
			return (R);
	return (RR);
}

int scroll_to(t_global *g, t_tab *tab, int target, int largest)
{
	int direction;

	direction = r_or_rr(tab, target);
	while (tab->data[0] != target)
	{
		if (tab->data[0] == largest)
		{
			pb(g);
			largest = find_largest(g->a);
			rb(g);
			return 0;
		}
		if (direction == R)
			rotate(g, A);
		if (direction == RR)
			reverse(g, A);
	}
	return 1;
}

void		sort_main(t_global *g)
{
	int smallest;
	int largest;

	check_simple_cases(g);

	while (A_SIZE > 3)
	{
		smallest = find_smallest(g->a);
		largest = find_largest(g->a);
		if (scroll_to(g, g->a, smallest, largest) == 1)
			pb(g);
	}
	sort_three(g, g->a->data);
	/*largest = find_largest(g->a);*/
	/*scroll_to(g, g->b, largest, 999999);*/
	while (B_SIZE > 0)
		pa(g);

	smallest = find_smallest(g->a);
	while (A_DATA[0] != smallest)
		ra(g);
	/*print_all(g);*/
}
