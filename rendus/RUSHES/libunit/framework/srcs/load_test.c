/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:19:27 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 17:22:00 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	load_test(t_unit_test **test_list, char *tested_function
	, char *test_name, int (*f)(void))
{
	t_unit_test	*tmp;

	if ((*test_list) == NULL)
	{
		(*test_list) = (t_unit_test *)malloc(sizeof(t_unit_test));
		(*test_list)->name = test_name;
		(*test_list)->tested_function = tested_function;
		(*test_list)->f = f;
		(*test_list)->next = NULL;
	}
	else
	{
		tmp = *test_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_unit_test *)malloc(sizeof(t_unit_test));
		tmp->next->f = f;
		tmp->next->name = test_name;
		tmp->next->tested_function = tested_function;
		tmp->next->next = NULL;
	}
}
