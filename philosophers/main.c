/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:30:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/19 20:38:43 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"





void ph_check_arguments(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				ph_print_exit("Arguments must be ints");
			j++;
		}
		j = 0;
		i++;
	}
}

int main(int ac, char **av)
{
	(void)av;
	if (!(ac == 4 || ac == 5))
		ph_print_usage();
	ph_check_arguments(ac, av);
}
