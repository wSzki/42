#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/08/29 23:00:27 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo
CC				= gcc
HEADER			= ./includes
FLAGS			= -Wall -Wextra -Werror -pthread
THREAD_CHECK	= -fsanitize=thread
LEAK_CHECK		= -fsanitize=address -fsanitize=leak
VALGRINDERS		= -ggdb3
OPTIMIZERS		= -O3
RM				= /bin/rm -f

SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES	= \
			  ph_check_arguments.c \
			  ph_init_struct.c \
			  ph_start.c \
			  utils/ph_putstr.c \
			  utils/ph_malloc.c \
			  utils/ph_timestamp.c \
			  utils/ph_atoi_overflow.c \

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

leak_sanitized:	fclean ${OBJS}
	${CC} ${FLAGS} ${LEAK_CHECK} ./main.c ${OBJS} -o ${NAME}

thread_sanitized:	fclean ${OBJS}
	${CC} ${FLAGS} ${THREAD_CHECK} ./main.c ${OBJS} -o ${NAME}

valgrinded:	fclean ${OBJS}
	${CC} ${FLAGS} ${VALGRINDERS} ./main.c ${OBJS} -o ${NAME}

optimized:	fclean ${OBJS}
	${CC} ${FLAGS} ${OPTIMIZERS} ./main.c ${OBJS} -o ${NAME}

.PHONY:\
	all fclean clean re \
	leak_sanitized \
	thread_sanitized \
	valgrinded \
	optimized
