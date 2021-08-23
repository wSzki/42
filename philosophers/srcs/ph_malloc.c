/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:01:05 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/23 18:21:10 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ph_malloc(t_global *g, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ph_putstr(2, "Error\n");
		ph_putstr(2, "malloc failed");
		ph_putstr(2, "\n");
		ph_free_everything_exit(g, ERROR);
	}
	return (ptr);
}
