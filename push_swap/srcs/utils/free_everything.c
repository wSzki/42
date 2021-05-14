/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:26:04 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/14 21:27:22 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	free_everything(t_global *g)
{
	free(g->a->data);
	free(g->b->data);
	free(g->a);
	free(g->b);
	free(g);
}
