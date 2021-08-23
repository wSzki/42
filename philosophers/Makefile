#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/08/23 18:18:49 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= gcc
HEADER		= ./includes
FLAGS		= -Wall -Wextra -Werror -pthread -fsanitize=address
RM			= /bin/rm -f

SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES	= \
			  ph_utils.c \
			  ph_check_arguments.c \
			  ph_malloc.c \
			  ph_atoi_overflow.c \

OBJS		= ${SRCS:.c=.o}

%.o: %.c
	${CC} ${FLAGS} -I ${HEADER} -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
	${CC} ${FLAGS} ./main.c ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY: 		all fclean clean re


