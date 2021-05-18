/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sa_sb_ss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:56:58 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/18 03:25:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	sub_s(t_tab *tab)
{
	int tmp;

	if (tab)
		if (tab->size)
			if (*tab->size > 1)
			{
				tmp = 0;
				tmp = tab->data[0];
				tab->data[0] = tab->data[1];
				tab->data[1] = tmp;
			}
	return ;
}

void		sa(t_global *g)
{
	if (*g->a->size > 1)
	{
		sub_s(g->a);
		write(1, "sa\n", 3);
	}
}

void		sb(t_global *g)
{
	if (*g->b->size > 1)
	{
		sub_s(g->b);
		write(1, "sb\n", 3);
	}
}

void		ss(t_global *g)
{
	sub_s(g->a);
	sub_s(g->b);
	return ;
}
