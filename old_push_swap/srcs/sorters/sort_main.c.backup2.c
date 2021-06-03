/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:02:50 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/26 13:04:46 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
void	print_all(t_global *g);
static int	find_smallest_number(t_tab *tab)
{
	int smallest_number;
	int i;

	i = 1;
	if (*tab->size == 0 || *tab->size == 1)
		return (0);
	smallest_number = tab->data[0];
	while (i < *tab->size)
	{
		if (tab->data[i] < smallest_number)
			smallest_number = tab->data[i];
		i++;
	}
	return (smallest_number);
}

static int	find_largest_number(t_tab *tab)
{
	int largest;
	int i;

	i = 1;
	if (*tab->size == 0 || *tab->size == 1)
		return (0);
	largest = tab->data[0];
	while (i < *tab->size)
	{
		if (tab->data[i] > largest)
			largest = tab->data[i];
		i++;
	}
	return (largest);
}

int	is_sorted(t_global *g)
{
	int i;

	i = 0;
	while (++i < *g->a->size)
		if (g->a->data[i] < g->a->data[i - 1])
			break ;
	if (i == *g->a->size)
		return (1);
	return (0);
}

static int	choose_direction(t_tab *tab, int wanted_value)
{
	int i;

	i = -1;
	while (++i < *tab->size / 2)
		if (tab->data[i] == wanted_value)
			return (R);
	return (RR);
}

static int	choose_direction2(t_global *g, t_tab *tab, int value)
{
	int i;
	int direction;
	int *b;
	b = g->b->data;

	i = 0;
	direction = 1;
	while (i < *tab->size / 2)
	{
		if (value > b[i] && value < b[i + 1])
			direction = 0;
		i++;
	}
	return (direction);
}

static void fill_b_with_three_sorted_values(t_global *g)
{
	int i;
	/*int a0;*/
	/*int b0;*/
	/*int b1;*/

	i = 0;
	/*a0 = g->a->data[0];*/
	/*b0 = g->b->data[0];*/
	/*b1 = g->b->data[1];*/
	while (i < 3)
	{
		if (*g->b->size < 3)
		{
			if (*g->b->size < 2)
				pb(g);
			else if (*g->b->size == 2)
			{
				pb(g);
				sort_three(g, g->b->data);
			}
		}
		i++;
	}
}

static void push_smallest(t_global *g, t_tab *tab, int small)
{
	while (tab->data[0] != small)
	{
		if (choose_direction(tab, small) == 0)
			rb(g);
		else
			rrb(g);
	}
	pb(g);
}

static void push_largest(t_global *g, t_tab *tab, int large)
{
	while(tab->data[0] != large)
		rb(g);
	rb(g);
	pb(g);
}


void	check_simple_cases(t_global *g)
{
	if_a_sorted_exit(g);
	if_two_sort_exit(g);
	if_three_sort_exit(g);
}


void		sort_main(t_global *g)
{
	int *a;
	int *b;
	int small;
	int large;

	check_simple_cases(g);

	fill_b_with_three_sorted_values(g);
	small = find_smallest_number(g->b);
	large = find_largest_number(g->b);

	//////////////////////////////////////////////////////////////////////
	int i = 0;
	int initial_size = *g->a->size;
	while (*g->a->size > initial_size / 2)
	{
		a = g->a->data;
		b = g->b->data;
		small = find_smallest_number(g->b);
		large = find_largest_number(g->b);

		/*printf("SMALL %d\n", small);*/
		/*printf("LARGE %d\n", large);*/
		/*printf("SIZE %d\n", *g->b->size);*/
		/*printf("A[0] %d\n", a[0]);*/
		/*printf("B[0] %d\n", b[0]);*/

		// if smallest
		if (a[0] < small)
		{
			push_smallest(g, g->b, small);
			small = a[0];
		}
		// if largest
		else if (a[0] > large)
		{
			push_largest(g, g->b, large);
			large = a[0];
		}
		// ignore if b[-1] b[0] b[1] is largest of smallest
		else if ((b[0] == small || b[0] == large) || (b[*g->b->size - 1] == small || b[*g->b->size - 1] == large) || (b[1] == small || b[1] == large))
			rb(g);
		else
		{
			/*while (!((a[0] < b[0] || ((b[0] == large)) || b[0] == small) && (a[0] > b[*g->b->size] || b[*g->b->size] == small || b[*g->b->size] == large)))*/
			// find correct spot
			while (!((a[0] < b[0]) && (a[0] > b[*g->b->size - 1])))
			{
				if (choose_direction2(g, g->b, a[0]) == 0)
					rb(g);
				/*else if (choose_direction2(g, g->b, a[0]) == 1)*/
				/*rb(g);*/
				else
					rrb(g);
			}
			// insert
			if (a[0] < b[0] && a[0] > b[*g->b->size - 1])
			{
				pb(g);
				i++;
			}
		}
		ra(g);
	}
	print_all(g);
}


