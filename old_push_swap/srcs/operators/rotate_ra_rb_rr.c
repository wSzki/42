/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ra_rb_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:07:26 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/27 16:59:14 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	sub_r(t_tab *tab)
{
	int i;
	int tmp;

	i = 0;
	if (tab)
		/*if (tab->size)*/
		if (tab->size > 1)
		{
			tmp = tab->data[0];
			while (i < tab->size)
			{
				tab->data[i] = tab->data[i + 1];
				i++;
			}
			tab->data[tab->size - 1] = tmp;
		}
	return ;
}

void		ra(t_global *g)
{
	if (g->a->size > 1)
	{
		sub_r(g->a);
		write(1, "ra\n", 3);
	}
	return ;
}

void		rb(t_global *g)
{
	if (g->b->size > 1)
	{
		sub_r(g->b);
		write(1, "rb\n", 3);
	}
	return ;
}


void		rotate(t_global *g, int id)
{
	if (id == A && A_SIZE > 1)
	{
			sub_r(g->a);
			write(1, "ra\n", 3);
	}
	if (id == B && B_SIZE > 1)
	{
			sub_r(g->b);
			write(1, "rb\n", 3);
	}

}

void		rr(t_global *g)
{
	sub_r(g->a);
	sub_r(g->b);
	write(1, "rr\n", 3);
	return ;
}
