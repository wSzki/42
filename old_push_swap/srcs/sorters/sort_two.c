/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:43:28 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/26 12:45:22 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	if_two_sort_exit(t_global *g)
{
	if (*g->a->size == 2)
	{
		if (g->a->data[0] > g->a->data[1])
			sa(g);
		free_everything(g);
		exit(0);
	}
}
