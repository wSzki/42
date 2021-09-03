/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:33:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/29 22:56:47 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ph_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		i++;
	write(fd, str, i);
}
