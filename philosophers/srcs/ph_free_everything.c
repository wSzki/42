/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_free_everything.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:14:50 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/24 16:15:19 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ph_free_everything_exit(t_global *g, int errno)
{
	if (errno == ERROR)
		ph_putstr(2, "Error\nMemory error\n");
	free(g->p);
	free(g);
	exit(errno);
}
