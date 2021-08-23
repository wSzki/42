/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_atoi_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:40:21 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/23 18:20:36 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ph_print_exit(char *str)
{
	ph_putstr(2, "Error\n");
	ph_putstr(2, str);
	ph_putstr(2, "\n");
	exit(ERROR);
}

static int	ph_count_numbers(int n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	process_pre_atoi(const char *str, int *i, int *sign)
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

static void	ph_convert(const char *str, int *atoi, int *i, int *number_count)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*atoi = *atoi * 10 + str[*i] - 48;
		*number_count += 1;
		*i += 1;
	}
}

int	ph_atoi_overflow(t_global *g, const char *str)
{
	int	atoi;
	int	sign;
	int	number_count;
	int	i;

	i = 0;
	number_count = 0;
	sign = 1;
	atoi = 0;
	process_pre_atoi(str, &i, &sign);
	ph_convert(str, &atoi, &i, &number_count);
	i = ph_count_numbers(atoi);
	if (i == number_count)
	{
		if (atoi > -1)
			return (atoi * sign);
		if (atoi == -2147483648 && sign == -1)
			return (atoi);
	}
	free(g);
	ph_print_exit("Integer overflow detected");
	return (0);
}
