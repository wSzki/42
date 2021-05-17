/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:02:50 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/17 19:59:04 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static int	find_smallest_number(t_tab *tab)
{
	int smallest_number;
	int i;

	i = 1;
	smallest_number = tab->data[0];
	while (i < *tab->size)
	{
		if (tab->data[i] < smallest_number)
			smallest_number = tab->data[i];
		i++;
	}
	return (smallest_number);
}

static int	choose_ra_or_rra(t_global *g, int smallest_number)
{
	int i;
	int j;
	int last_number_index;

	i = 0;
	j = 0;
	last_number_index = *g->a->size;
	while (g->a->data[i] != smallest_number && i < *g->a->size)
		i++;
	while (g->a->data[last_number_index - 1] != smallest_number &&\
			smallest_number >= 0)
	{
		last_number_index--;
		j++;
	}
	if (i < j)
		return (0);
	return (1);
}

static void	place_smallest_number_first(t_global *g, int smallest_number)
{
	int direction;

	direction = choose_ra_or_rra(g, smallest_number);
	while (g->a->data[0] != smallest_number)
	{
		if (direction == 0)
			ra(g);
		if (direction == 1)
			rra(g);
	}
	return ;
}

void		sort_main(t_global *g)
{
	int i;
	int smallest_number;

	i = 0;
	is_a_sorted(g);
	sort_two(g);
	if (*g->a->size == 3)
	{
		sort_three(g);
		return ;
	}
	smallest_number = find_smallest_number(g->a);
	while (i < *g->a->size)
	{
		if (*g->a->size == 3)
		{
			sort_three(g);
			break ;
		}
		smallest_number = find_smallest_number(g->a);
		place_smallest_number_first(g, smallest_number);
		pb(g);
	}
	while (*g->b->size > 0)
		pa(g);
}
