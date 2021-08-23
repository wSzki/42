/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:31:02 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/23 18:16:13 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>


# define ERROR 1
# define OK 0

typedef struct s_global {

	int n_philo;
	int t_die;
	int t_eat;
	int t_sleep;


}	t_global;

void	ph_putstr(int fd, char *str);
void	ph_check_arguments(int ac, char **av);
void	*ph_malloc(t_global *g, size_t size);
void	ph_free_everything_exit(void *g, int errno);
int	ph_atoi_overflow(t_global *g, const char *str);


#endif
