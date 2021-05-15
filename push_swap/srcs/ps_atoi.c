/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:22:55 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/15 18:08:56 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	ft_count_numbers(int n)
{
	size_t i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int			ps_atoi(const char *str, t_global *g)
{
	int	atoi;
	int			sign;
	int			j;
	int			i;

	i = 0;
	j = 0;
	sign = 1;
	atoi = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && j++ >= 0)
		atoi = atoi * 10 + str[i++] - 48;
	if (str[i] != 0)
		free_everything_and_exit(g);
	i = ft_count_numbers(atoi);
	if (i == j)
		if (atoi > -1 || atoi == -2147483648)
			return (atoi * sign);
	free_everything_and_exit(g);
	return (0);
}

