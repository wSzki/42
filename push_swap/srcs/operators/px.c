/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:19:09 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/08 19:38:23 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	px(t_global *g, int id)
{
	if (id == A_ID)
	{
		if (B)
		{
			if (B_SIZE > 0)
			{
				ps_prepend(g, A, B_DATA[0]);
				ps_delete_first(g, B);
				write(1, "pa\n", 3);
			}
		}
	}
	if (id == B_ID)
	{
		if (A)
		{
			if (A_SIZE > 0)
			{
				ps_prepend(g, B, A_DATA[0]);
				ps_delete_first(g, A);
				write(1, "pb\n", 3);
			}
		}
	}
}
