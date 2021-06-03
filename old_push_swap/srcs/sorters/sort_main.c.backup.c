/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:02:50 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/19 04:22:27 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
void	print_all(t_global *g);
static int	find_smallest_number(t_tab *tab)
{
	int smallest_number;
	int i;

	i = 1;
	if (*tab->size == 0)
		return (0);
	if (*tab->size == 1)
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
	if (*tab->size == 0)
		return (0);
	if (*tab->size == 1)
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
/*
   static void	place_smallest_number_first(t_global *g, int smallest_number)
   {
   int i;
   int direction;

   i = 0;
   direction = 1;
   while (i < *g->a->size / 2 + 1)
   {
   if (g->a->data[i] == smallest_number)
   direction = 0;
   i++;
   }
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
   */
int	is_sorted(t_global *g)
{
	int i;

	i = 1;
	while (i < *g->a->size)
	{
		if (g->a->data[i] < g->a->data[i - 1])
			break ;
		i++;
	}
	if (i == *g->a->size)
	{
		return 1;
	}
	return 0;
}

static int	choose_direction(t_tab *tab, int wanted_value)
{
	int i;
	int direction;

	i = 0;
	direction = 1;
	while (i < *tab->size / 2)
	{
		if (tab->data[i] == wanted_value)
			direction = 0;
		i++;
	}
	return (direction);
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
void		sort_main(t_global *g)
{


	int *a;
	int *b;
	int small;
	int large;
	is_a_sorted(g);
	sort_two(g);
	if (*g->a->size == 3)
	{
		sort_three(g, g->a->data);
		return ;
	}
	//////////////////////////////////////////////////////////////////////
	int i = 0;
	int initial_size = *g->a->size;
	while (*g->a->size > initial_size / 2  )
	{
		a = g->a->data;
		b = g->b->data;
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
		else
		{
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
				while (b[0] != small)
				{
					if (choose_direction(g->b, small) == 0)
						rb(g);
					else
						rrb(g);
				}
				small = a[0];
				pb(g);
				i++;
			}
			// if largest
			else if (a[0] > large)
			{
				while(b[0] != large)
					rb(g);
				large = a[0];
				rb(g);
				pb(g);
				i++;
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
	}
	/*print_all(g);*/
}


