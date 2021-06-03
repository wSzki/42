/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:14:13 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/27 19:58:41 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define R 0
#define RR 1
#define A 0
#define B 1
#define A_DATA g->a->data
#define B_DATA g->b->data
#define A_SIZE g->a->size
#define B_SIZE g->b->size
#define A_LARGE g->a->largest
#define B_LARGE g->b->largest
#define A_SMALL g->b->largest
#define B_SMALL g->b->largest

typedef struct s_tab
{
	int id;
	int *data;
	int size;
	int largest;
	int smallest;

}			t_tab;

typedef struct s_global
{
	int *tab_a;
	int *tab_b;

	int tab_a_size;
	int tab_b_size;

	t_tab *a;
	t_tab *b;

	char **av;
}				t_global;


int			ps_atoi(const char *str, t_global *g);
void		print_error_and_exit(void);
void		free_everything_and_exit(t_global *g);
void		free_everything(t_global *g);

void	ps_prepend(t_global *g, t_tab *tab, int value);
void	ps_append(t_global *g, t_tab *tab, int value);
void	ps_delete_first(t_global *g, t_tab *tab);

void	fill_tab_a(t_global *g, int ac, char **av);

void ss(t_global *g);
void sb(t_global *g);
void sa(t_global *g);
void pb(t_global *g);
void pa(t_global *g);
void rotate(t_global *g, int id);
void reverse(t_global *g, int id);
void ra(t_global *g);
void rb(t_global *g);
void rr(t_global *g);
void rra(t_global *g);
void rrb(t_global *g);
void rrr(t_global *g);

void check_simple_cases(t_global *g);
void sort_main(t_global *g);
//void if_two_sort_exit(t_global *g);
void sort_three(t_global *g, int *tab);
//void if_three_sort_exit(t_global *g);
//void if_a_sorted_exit(t_global *g);
#endif
