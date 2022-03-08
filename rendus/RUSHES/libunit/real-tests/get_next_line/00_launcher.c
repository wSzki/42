/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:48:28 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 23:28:26 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "gnl_tests.h"

int	gnl_launcher(void)
{
	t_unit_test	*list;

	list = NULL;
	load_test(&list, "get_next_line", "Read entire file", &basic_test);
	load_test(&list, "get_next_line", "Invalid fd", &invalid_fd);
	load_test(&list, "get_next_line", "One line read", &basic_test_one);
	load_test(&list, "get_next_line", "Multiple fd", &multiple_fd);
	load_test(&list, "get_next_line", "Null line", &null_test);
	load_test(&list, "get_next_line", "Check last return", &return_check);
	load_test(&list, "get_next_line", "Read whithout \\n", &no_nl);
	load_test(&list, "get_next_line", "Empty file", &empty);
	load_test(&list, "get_next_line", "Unicode", &unicode_test);
	load_test(&list, "get_next_line", "Special chars", &special_char_test);
	load_test(&list, "get_next_line", "A thousand newlines", &many_newlines);
	load_test(&list, "get_next_line", "Null if error", &null_line_if_error);
	load_test(&list, "get_next_line", "Opening a folder as file", &open_folder);
	load_test(&list, "get_next_line", "Opening a locked file", &protected_file);
	load_test(&list, "get_next_line", "A thousand newlines", &many_newlines);
	load_test(&list, "get_next_line", "Empty ret", &empty_ret);
	return (launch_test(list));
}
