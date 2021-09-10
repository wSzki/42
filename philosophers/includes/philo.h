/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:31:02 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/03 13:34:36 by wszurkow         ###   ########.fr       */
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

typedef struct s_philosopher
{
	int		id;
	long	t_last_meal;
	int		left_fork_id;
	int		right_fork_id;
	int		meals_eaten;
}	t_philosopher;

typedef struct s_global {
	int				 i;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals_to_eat;
	int				n_deaths;
	int				n_satiated;
	pthread_mutex_t				lock;
	pthread_mutex_t				*forks;
	t_philosopher	*p;
}	t_global;

void	*ph_malloc(t_global *g, size_t size);
void	ph_putstr(int fd, char *str);
void	ph_check_arguments(int ac, char **av);
void	ph_free_everything_exit(t_global *g, int errno);
int		ph_atoi_overflow(t_global *g, const char *str);
void	ph_init_struct(t_global *g, int ac, char **av);
int		ph_start(t_global *g);
long	ph_timestamp(void);
#endif
