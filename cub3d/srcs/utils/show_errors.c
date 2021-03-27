/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:30:09 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/27 16:30:33 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void show_errors(t_global *g)
{
	printf("Error\n");
	int i = -1;
	if (*(g->error))
	{
		while (((g->error)[++i]) != NULL)
			ft_putstr((g->error)[i]);
	}
}
