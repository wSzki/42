/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:39:18 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/15 16:39:43 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ps_append(t_global *g, t_tab *tab, int value)
{
	int i;
	int *res;

	i = 0;
	*tab->size += 1;
	res = malloc (sizeof(int) * *tab->size);
	if (!res)
		free_everything_and_exit(g);
	while (i < *tab->size - 1)
	{
		res[i] = tab->data[i];
		i++;
	}
	res[i] = value;
	free(tab->data);
	tab->data = res;
	return ;
}
