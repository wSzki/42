/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:34:31 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 23:26:05 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	catch_signal_child(t_unit_test *list, t_unit_test *first_element)
{
	pid_t	pid;
	int		code;

	pid = fork();
	if (pid == -1)
		exit_error("Fork launch_test.c error\n", first_element);
	if (pid == 0)
	{
		exit(list->f() + 1);
	}
	wait(&code);
	if (WIFEXITED(code))
		return (WEXITSTATUS(code));
	if (WIFSIGNALED(code))
		return (WTERMSIG(code));
	return (0);
}

static void	output_message(int code, t_unit_test *list, t_buf *buffer)
{
	buf_write(buffer, 1, list->tested_function,
		ft_strlen(list->tested_function));
	buf_write(buffer, 1, ": ", 2);
	buf_write(buffer, 1, list->name, ft_strlen(list->name));
	buf_write(buffer, 1, ": ", 2);
	if (code == 1)
		buf_write(buffer, 1, "[OK]", 4);
	else if (code == 0)
		buf_write(buffer, 1, "[KO]", 4);
	else if (code == SIGBUS)
		buf_write(buffer, 1, "[SIGBUS]", 8);
	else if (code == SIGSEGV)
		buf_write(buffer, 1, "[SIGSEGV]", 9);
	buf_write(buffer, 1, "\n", 1);
}

static void	output_result(t_count count, t_buf *buffer)
{
	buf_write(buffer, 1, "\n", 1);
	buf_write_ulong(buffer, count.succeed);
	buf_write(buffer, 1, "/", 1);
	buf_write_ulong(buffer, count.nb_tests);
	buf_write(buffer, 1, " tests checked\n", 16);
}

int	launch_test(t_unit_test *list)
{
	int			flag;
	int			code;
	t_buf		buffer;
	t_unit_test	*first_element;
	t_count		count;

	ft_bzero(&count, sizeof(t_count));
	buffer.len = 0;
	flag = 0;
	first_element = list;
	while (list)
	{
		code = catch_signal_child(list, first_element);
		if (code != 0)
			flag = -1;
		output_message(code, list, &buffer);
		if (code == 1)
			count.succeed++;
		count.nb_tests++;
		list = list->next;
	}
	output_result(count, &buffer);
	write(1, buffer.buf, buffer.len);
	free_list(first_element);
	return (flag);
}
