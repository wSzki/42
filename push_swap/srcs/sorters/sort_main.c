/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:02:50 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/18 00:26:23 by wszurkow         ###   ########.fr       */
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
void		sort_main(t_global *g)
{


	print_all(g);
	is_a_sorted(g);
	sort_two(g);
	if (*g->a->size == 3)
	{
		sort_three(g);
		return ;
	}
	int i = 0;
	int small = find_smallest_number(g->a);
	int large = find_largest_number(g->a);
	while (i < 200)
	{
		if (is_sorted(g))
			break;
		else if (g->a->data[0] > small && g->a->data[0] < large)
		{
			large = g->a->data[0];
			pb(g);
		}
		else if (g->a->data[0] > large)
		{
			pb(g);
			rb(g);
		}
		print_all(g);
		ra(g);
		i++;
	}

}


