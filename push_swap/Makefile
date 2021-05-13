# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/05/13 18:36:25 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pushswap.a
SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES	= \
			  utils/free_everything.c \
			  utils/print_error_and_exit.c \
			  ps_atoi.c \


OBJS		= ${SRCS:.c=.o}
%.o: %.c
	gcc -Wall -Werror -Wextra -I ./includes -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}

exec:		pushswap.a
	clear
	gcc -Wall -Werror -Wextra main.c ${NAME} \
		-I ./includes \
	./a.out

clean:
	rm -f ${OBJS}
	rm -f a.out

fclean:		clean
	rm -f ./${NAME}

re:			fclean all

.PHONY: 		all fclean clean re


