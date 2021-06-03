/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:44:50 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/19 04:25:58 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	if_a_sorted_exit(t_global *g)
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
		free_everything(g);
		exit(0);
	}
}
