/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:14:13 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/13 18:39:43 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_global
{
	int *tab_a;
	int *tab_b;

	int tab_a_size;
	int tab_b_size;

	char **av;
}				t_global;


int			ps_atoi(const char *str, t_global *g);
void		print_error_and_exit(t_global *g);
void	free_everything(t_global *g);


#endif
