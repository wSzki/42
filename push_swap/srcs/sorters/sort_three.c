/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:01:04 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/27 22:05:25 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void sort_three(t_global*g, int *tab)
{
	if (tab[0] > tab[1] && tab[1] < tab[2])
		sa(g);
	if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		sa(g);
		rra(g);
	}
	if (tab[0] > tab[1] && tab[1] < tab[2])
		ra(g);
	if (tab[1] > tab[0] && tab[1] > tab[2] && tab[2] > tab[0])
	{
		sa(g);
		ra(g);
	}
	if (tab[1] > tab[0] && tab[1] > tab[2] && tab[2] < tab[0])
		rra(g);
}
