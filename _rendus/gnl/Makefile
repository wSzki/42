# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 15:58:23 by wszurkow          #+#    #+#              #
#    Updated: 2021/06/17 16:20:02 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_gnl.a
COMPILER		= gcc
FLAGS			= -Wall -Werror -Wextra -fsanitize=address
SRCS			= $(addprefix ./, ${SRCS_FILES})
SRCS_FILES		= \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c \

OBJS			= ${SRCS:.c=.o}
%.o: %.c
	${COMPILER} ${FLAGS} -I ./ -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
	ar -rcs ft_gnl.a ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ft_gnl.a

re: fclean all

.PHONY:	all clean fclean re

