/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:34:56 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/19 20:37:15 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	ph_print_usage(void)
{
	ph_putstr("Error\n");
	ph_putstr("Usage: ");
	ph_putstr("./philo [number_of_philosophers] [time_to_die] [time_to_eat] ");
	ph_putstr("[time_to_sleep] ");
	ph_putstr("(OPTIONAL)[number_of_times_each_philosopher_must_eat]\n");
	exit(1);
}

void	ph_print_exit(char *str)
{
	ph_putstr("Error\n");
	ph_putstr(str);
	ph_putstr("\n");
}
