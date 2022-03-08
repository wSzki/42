# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 15:58:23 by wszurkow          #+#    #+#              #
#    Updated: 2022/01/09 21:18:35 by ggiquiau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= lib_to_test.a
COMPILER		= gcc
FLAGS			= -Wall -Werror -Wextra
SRCS			= $(addprefix ./, ${SRCS_FILES})
SRCS_FILES		= \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				str.c

OBJS			= ${SRCS:.c=.o}
%.o: %.c
	${COMPILER} ${FLAGS} -I ./ -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re

