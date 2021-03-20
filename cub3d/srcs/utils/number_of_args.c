/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:40:01 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/20 22:08:38 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	number_of_args(char **line)
{
	int	i;

	if (!line)
		return (0);
	if (!(*line))
		return (0);
	i = 0;
	while (line[i])
		i++;
	return (i);
}
