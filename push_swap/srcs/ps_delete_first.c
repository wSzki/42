/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_delete_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:40:00 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/15 16:40:14 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ps_delete_first(t_global *g, t_tab *tab)
{
	int i;
	int *res;

	i = 1;
	*tab->size -= 1;
	res = malloc (sizeof(int) * *tab->size);
	if (!res)
		free_everything_and_exit(g);
	while (i < *tab->size)
	{
		res[i] = tab->data[i];
		i++;
	}
	free(tab->data);
	tab->data = res;
	return ;
}
