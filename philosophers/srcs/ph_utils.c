/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:33:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/19 20:34:43 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ph_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		i++;
	write(2, str, i);
}
