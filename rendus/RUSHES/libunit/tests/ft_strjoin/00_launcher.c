/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:42:01 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 23:28:52 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_strjoin_tests.h"

int	ft_strjoin_launcher(void)
{
	t_unit_test	*list;

	list = NULL;
	load_test(&list, \
			"ft_strjoin", \
			"BASIC test for hello_world", \
			&basic_test_hello_world);
	load_test(&list, \
			"ft_strjoin", \
			"BASIC test for empty string", \
			&basic_test_empty_string);
	load_test(&list, \
			"ft_strjoin", \
			"BASIC test for special chars", \
			&basic_test_special_chars);
	load_test(&list, \
			"ft_strjoin", \
			"BASIC test for unicode", \
			&basic_test_unicode);
	load_test(&list, \
			"ft_strjoin", \
			"BASIC test for invalid pointer", \
			&basic_test_wrong_pointer);
	load_test(&list, \
			"ft_strjoin", \
			"BASIC test for bus error", \
			&basic_test_bus_error);
	return (launch_test(list));
}
