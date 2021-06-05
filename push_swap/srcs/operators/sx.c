/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:33:29 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/03 20:35:22 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	sub_s(t_tab *tab)
{
	int tmp;

	if (tab)
		if (tab->size > 1)
		{
			tmp = 0;
			tmp = tab->data[0];
			tab->data[0] = tab->data[1];
			tab->data[1] = tmp;
		}
	return ;
}

void	sx(t_global *g, int id)
{
	if (id == A_ID)
		if (A_SIZE > 1)
		{
			sub_s(A);
			write(1, "sa\n", 3);
		}
	if (id == B_ID)
		if (B_SIZE > 1)
		{
			sub_s(B);
			write(1, "sb\n", 3);
		}
	if (id == R_ID)
	{
		sub_s(A);
		sub_s(B);
		write(1, "ss\n", 3);

	}
}