/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:38:57 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/13 20:59:57 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

# include <stddef.h>

typedef struct s_heap
{
	int				nb_al;
	struct s_heap	*previous;
	struct s_heap	*next;
}	t_heap;

typedef struct s_board
{
	t_heap	*first;
	t_heap	*last;
	size_t	nb_of_heaps;
}	t_board;

int		parse_board(int fd, t_board *board);
t_board    *get_board(void);
void	display_board(t_board *board);

#endif
