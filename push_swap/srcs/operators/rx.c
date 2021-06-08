/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:25:41 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/08 19:35:49 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	sub_r(t_tab *tab)
{
	int	i;
	int	tmp;

	i = 0;
	if (tab)
	{
		if (tab->size > 1)
		{
			tmp = tab->data[0];
			while (i < tab->size - 1)
			{
				tab->data[i] = tab->data[i + 1];
				i++;
			}
			tab->data[tab->size - 1] = tmp;
		}
	}
	return ;
}

void	rx(t_global *g, int id)
{
	if (id == A_ID)
	{
		if (A_SIZE > 1)
		{
			sub_r(A);
			write(1, "ra\n", 3);
		}
	}
	if (id == B_ID)
	{
		if (B_SIZE > 1)
		{
			sub_r(B);
			write(1, "rb\n", 3);
		}
	}
	if (id == R_ID)
	{
		sub_r(A);
		sub_r(B);
		write(1, "rr\n", 3);
	}
}
