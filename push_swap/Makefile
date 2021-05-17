# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/05/17 16:31:34 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pushswap.a
SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES	= \
			  utils/free_everything.c \
			  utils/print_error_and_exit.c \
			  operators/swap_sa_sb_ss.c \
			  operators/push_pa_pb.c \
			  operators/rotate_ra_rb_rr.c \
			  operators/reverse_rra_rrb_rrr.c \
			  ps_delete_first.c \
			  ps_append.c \
			  ps_prepend.c \
			  ps_atoi.c \
			  ps_fill_tab_a.c \


OBJS		= ${SRCS:.c=.o}
%.o: %.c
	gcc -Wall -Werror -Wextra -I ./includes -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}
	@gcc -o push_swap -fsanitize=address -Wall -Werror -Wextra main.c pushswap.a -I ./includes

exec:		pushswap.a
	@gcc -fsanitize=address -Wall -Werror -Wextra main.c pushswap.a -I ./includes
	@./a.out

clean:
	rm -f ${OBJS}
	rm -f push_swap

fclean:		clean
	rm -f ./${NAME}

re:			fclean all

.PHONY: 		all fclean clean re


