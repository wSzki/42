/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rra_rrb_rrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:07:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/29 16:08:06 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	sub_rr(t_tab *tab)
{
	int tmp;
	int tmp_size;

	if (tab)
		/*if (tab->size)*/
			if (tab->size > 1)
			{
				tmp = tab->data[tab->size - 1];
				tmp_size = tab->size;
				while (tmp_size > 0)
				{
					tab->data[tmp_size] = tab->data[tmp_size - 1];
					tmp_size--;
				}
				tab->data[0] = tmp;
			}
	return ;
}

void		rra(t_global *g)
{
	if (g->a->size > 1)
	{
		sub_rr(g->a);
		write(1, "rra\n", 4);
	}
	return ;
}

void		rrb(t_global *g)
{
	if (g->b->size > 1)
	{
		sub_rr(g->b);
		write(1, "rrb\n", 4);
	}
	return ;
}


/*void		reverse(t_global *g, int id)*/
/*{*/
	/*if (id == A && A_SIZE > 1)*/
	/*{*/
			/*sub_rr(g->a);*/
			/*write(1, "rra\n", 4);*/
	/*}*/
	/*if (id == B && B_SIZE > 1)*/
	/*{*/
			/*sub_rr(g->b);*/
			/*write(1, "rrb\n", 4);*/
	/*}*/
/*}*/

void		rrr(t_global *g)
{
	sub_rr(g->a);
	sub_rr(g->b);
	write(1, "rrr\n", 4);
	return ;
}
