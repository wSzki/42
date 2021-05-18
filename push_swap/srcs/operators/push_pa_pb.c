/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pa_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:00:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/18 03:18:25 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	pa(t_global *g)
{
	if (g->b)
		if (g->b->size)
			if (*g->b->size > 0)
			{
				ps_prepend(g, g->a, g->b->data[0]);
				ps_delete_first(g, g->b);
				write(1, "pa\n", 3);
			}
	return ;
}

void	pb(t_global *g)
{
	if (g->a)
		if (g->a->size)
			if (*g->a->size > 0)
			{
				ps_prepend(g, g->b, g->a->data[0]);
				ps_delete_first(g, g->a);
				write(1, "pb\n", 3);
			}
	return ;
}
