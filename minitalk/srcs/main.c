/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:42:20 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/10 13:47:28 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../printf/includes/ft_printf.h"
#include "stdio.h"

void check_input_errors(int ac, char **av)
{
	if (ac != 1 || ac != 3)
		exit(0);
}

void client(pid_t pid, const char *message)
{
	// check if valid PID (pid_t format)
	// check if existing PID
	// connect to PID
	// send to PID


}

void server(int ac)
{
	int pid;
	pid = getpid();
	if (ac == 1)
	{
		ft_printf("PID = %d\n", pid);
		while (1);
			ac = 1;
		// launch server
		// // open ports
		// // keep while loop on
		// // implement KILL
		//
		//
		// // receive from client
		// // print message received
		exit(0);
	}
}


int main(int ac, char **av)
{

	check_input_errors(ac, av);
	server(ac);
	client((pid_t)ft_atoi(av[1], av[2]));
	// launch client
	//
}
