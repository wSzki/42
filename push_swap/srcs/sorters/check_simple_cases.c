/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:03:15 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/27 22:06:43 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	if_three_sort_exit(t_global *g)
{
	int *tab;

	tab = g->a->data;
	if (g->a->size == 3)
	{
		if (tab[0] > tab[1] && tab[1] < tab[2])
			sa(g);
		if (tab[0] > tab[1] && tab[1] > tab[2])
		{
			sa(g);
			rra(g);
		}
		if (tab[0] > tab[1] && tab[1] < tab[2])
			ra(g);
		if (tab[1] > tab[0] && tab[1] > tab[2] && tab[2] > tab[0])
		{
			sa(g);
			ra(g);
		}
		if (tab[1] > tab[0] && tab[1] > tab[2] && tab[2] < tab[0])
			rra(g);
		free_everything(g);
		exit(0);
	}
}

static void	if_two_sort_exit(t_global *g)
{
	if (g->a->size == 2)
	{
		if (g->a->data[0] > g->a->data[1])
			sa(g);
		free_everything(g);
		exit(0);
	}
}

static void	if_a_sorted_exit(t_global *g)
{
	int i;

	i = 1;
	while (i < g->a->size)
	{
		if (g->a->data[i] < g->a->data[i - 1])
			break ;
		i++;
	}
	if (i == g->a->size)
	{
		free_everything(g);
		exit(0);
	}
}

void		check_simple_cases(t_global *g)
{
	if_a_sorted_exit(g);
	if_two_sort_exit(g);
	if_three_sort_exit(g);
}
