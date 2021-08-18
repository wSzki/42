/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wsz_count_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:54:01 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/17 02:53:36 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libwsz.h"

size_t	wsz_count_lines(void **tab)
{
	int	i;

	if (!tab)
		return (0);
	if (!(*tab))
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}
