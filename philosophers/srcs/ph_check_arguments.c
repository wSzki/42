/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:34:56 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/23 18:22:16 by wszurkow         ###   ########.fr       */
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

static void	ph_print_usage_exit(void)
{
	ph_putstr(2, "Error\n");
	ph_putstr(2, "Usage: ");
	ph_putstr(2, "./philo [number_of_philosophers] ");
	ph_putstr(2, "[time_to_die] [time_to_eat] ");
	ph_putstr(2, "[time_to_sleep] ");
	ph_putstr(2, "(OPTIONAL)[number_of_times_each_philosopher_must_eat]\n");
	exit(ERROR);
}

void	ph_check_arguments(int ac, char **av)
{
	int	i;
	int	j;

	(void)av;
	i = 0;
	if (!(ac == 5 || ac == 6))
		ph_print_usage_exit();
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				ph_print_exit("Arguments must be positive integers");
	}
}
