/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:23:45 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 23:26:33 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H
# include "../ft_libft/libft.h"
# include <sys/wait.h>
# include <signal.h>
# define BUFFER_SIZE 4096

typedef struct s_unit_test
{
	int					(*f)(void);
	char				*name;
	char				*tested_function;
	struct s_unit_test	*next;

}	t_unit_test;

typedef unsigned long	t_ulong;

typedef struct s_buf
{
	char	buf[BUFFER_SIZE];
	int		len;
}			t_buf;

typedef struct s_count
{
	int	nb_tests;
	int	succeed;
}				t_count;

void	load_test(t_unit_test **t_list, char *tested_func, char *tname,
			int (*f)(void));
int		launch_test(t_unit_test *list);
void	buf_write(t_buf *buf, int fd, const void *src, int n);
void	buf_write_ulong(t_buf *buf, t_ulong l);
void	exit_error(char *str, t_unit_test *list);
char	*ft_lutoa(t_ulong n);
void	free_list(t_unit_test *list);
#endif
