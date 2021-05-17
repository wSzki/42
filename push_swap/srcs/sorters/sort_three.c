/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:01:04 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/17 19:48:37 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void sort_three(t_global *g)
{
	int *tab;

	tab = g->a->data;
	// 213
	if (tab[0] > tab[1] && tab[1] < tab[2])
		sa(g);
	// 321
	if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		sa(g);
		rra(g);
	}
	// 312
	if (tab[0] > tab[1] && tab[1] < tab[2])
		ra(g);
	// 132
	if (tab[1] > tab[0] && tab[1] > tab[2] && tab[2] > tab[0])
	{
		sa(g);
		ra(g);
	}
	// 231
	if (tab[1] > tab[0] && tab[1] > tab[2] && tab[2] < tab[0])
		rra(g);
}

