#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/09/07 17:16:41 by adlancel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex 
CC				= gcc
HEADER			= ./includes
FLAGS			= -Wall -Wextra -Werror
THREAD_CHECK	= -fsanitize=thread
LEAK_CHECK		= -fsanitize=address 
VALGRINDERS		= -ggdb3
OPTIMIZERS		= -O3
RM				= /bin/rm -f

SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES	= \
				utils/p_split.c \
				utils/p_strcat.c \
				utils/p_strcpy.c \
				utils/p_strlen.c \
				utils/p_strjoin.c \
				utils/p_strncmp.c \
				p_parse_args.c \
				p_check_commands.c \

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
