/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ra_rb_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:03:54 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/16 14:28:55 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	sub_r(t_tab *tab)
{
	int size;
	int tmp;

	if (tab)
		if (tab->size)
			if (*tab->size > 1)
			{
				size = *tab->size;
				tmp = tab->data[size - 1];
				while (size > 0)
				{
					tab->data[size] = tab->data[size - 1];
					size--;
				}
				tab->data[0] = tmp;
			}
	return ;
}

void		ra(t_global *g)
{
	sub_r(g->a);
	write(2, "ra\n", 3);
	return ;
}

void		rb(t_global *g)
{
	sub_r(g->b);
	write(2, "rb\n", 3);
	return ;
}

void		rr(t_global *g)
{
	sub_r(g->a);
	sub_r(g->b);
	write(2, "rr\n", 3);
	return ;
}
