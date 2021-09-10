/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:30:42 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/09 17:40:47 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/adl_minishell.h"
#include "../includes/minishell.h"

typedef struct	s_list_chainee
{
	char	*name;
	void	*next;
}				t_list_chainee;

int main()
{
	t_list_chainee *p1;
	t_list_chainee *p2;
	t_list_chainee *p3;


	p1 = malloc(sizeof(t_list_chainee));
	p2 = malloc(sizeof(t_list_chainee));
	p3 = malloc(sizeof(t_list_chainee));
	p1->name = "william";
	p2->name = "didi";
	p3->name = "tom";

	p1->next = p2;
	p2->next = p3;
	p3->next = NULL;


	t_list_chainee *current_list;

	current_list = p1;
	while (current_list->next)
	{
		printf ("%s\n", current_list->name);
		current_list = current_list->next;
	}
		printf ("%s\n", current_list->name);
}


