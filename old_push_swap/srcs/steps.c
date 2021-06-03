/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:10:45 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/26 11:21:55 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int direction_to_smallest_value(t_tab *tab)
{
	int i;

	i = 0;
	while (i < *tab->size / 2)
	{
		if (tab->data[i] == tab->smallest)
			return (0);
		i++;
	}
	return (1);
}
int direction_to_largest_value(t_tab *tab)
{
	int i;

	i = 0;
	while (i < *tab->size / 2)
	{
		if (tab->data[i] == tab->largest)
			return (0);
		i++;
	}
	return (1);
}
