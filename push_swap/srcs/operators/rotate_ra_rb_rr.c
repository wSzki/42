/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ra_rb_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:07:26 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/17 15:01:55 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	sub_r(t_tab *tab)
{
	int i;
	int size;
	int tmp;

	i = 0;
	if (tab)
		if (tab->size)
			if (*tab->size > 1)
			{
				size = *tab->size;
				tmp = tab->data[0];
				while (i < size)
				{
					tab->data[i] = tab->data[i + 1];
					i++;
				}
				tab->data[size - 1] = tmp;
			}
	return ;
}

void		ra(t_global *g)
{
	sub_r(g->a);
	write(1, "ra\n", 3);
	return ;
}

void		rb(t_global *g)
{
	sub_r(g->b);
	write(1, "rb\n", 3);
	return ;
}

void		rr(t_global *g)
{
	sub_r(g->a);
	sub_r(g->b);
	write(1, "rr\n", 3);
	return ;
}
