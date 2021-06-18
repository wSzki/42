/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:40:21 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/18 14:49:26 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	process_pre_data(const char *str, int *i, int *sign)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || (str[*i] == 32))
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -(*sign);
		*i += 1;
	}
	while (str[*i] == '0')
		*i += 1;
}

static void	convert(const char *str, int *atoi, int *i, int *number_count)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*atoi = *atoi * 10 + str[*i] - 48;
		*number_count += 1;
		*i += 1;
	}
}

int	ft_atoi_overflow(const char *str, void *g, void (*free_and_exit)(void *))
{
	int	atoi;
	int	sign;
	int	number_count;
	int	i;

	i = 0;
	number_count = 0;
	sign = 1;
	atoi = 0;
	process_pre_data(str, &i, &sign);
	convert(str, &atoi, &i, &number_count);
	if (str[i] != 0)
		free_and_exit(g);
	i = ft_count_numbers(atoi);
	if (i == number_count)
	{
		if (atoi > -1)
			return (atoi * sign);
		if (atoi == -2147483648 && sign == -1)
			return (atoi);
	}
	ft_putstr("ERROR: atoi overflow\n");
	free_and_exit(g);
	return (0);
}

