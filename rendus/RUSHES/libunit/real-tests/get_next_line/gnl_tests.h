/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:46:40 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 21:38:23 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_TESTS_H
# define GNL_TESTS_H
# include "libunit.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int	basic_test(void);
int	basic_test_one(void);
int	invalid_fd(void);
int	multiple_fd(void);
int	null_test(void);
int	no_nl(void);
int	empty(void);
int	gnl_launcher(void);
int	get_next_line(int fd, char **line);
int	return_check(void);
int	unicode_test(void);
int	special_char_test(void);
int	open_folder(void);
int	protected_file(void);
int	many_newlines(void);
int	null_line_if_error(void);
int	empty_ret(void);

#endif
