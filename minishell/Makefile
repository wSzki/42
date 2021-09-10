#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/09/10 14:58:18 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell
CC				= gcc
HEADER			= ./includes
FLAGS			= -Wall -Wextra -Werror -lreadline -fsanitize=address
THREAD_CHECK	= -fsanitize=thread
LEAK_CHECK		= -fsanitize=address -fsanitize=leak
VALGRINDERS		= -ggdb3
OPTIMIZERS		= -O3
RM				= /bin/rm -f

SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES	= \
			  utils/ft_split.c \
			  utils/ft_strlen.c \
			  utils/ft_strncmp.c \
			  utils/ft_strjoin.c \
			  \
			  utils/ms_exec.c \
			  \
			  pipex/call_child.c \
			  pipex/call_parent.c \
			  pipex/find_absolute_path.c \
			  pipex/pipex.c \
			  \

OBJS		= ${SRCS:.c=.o}

%.o: %.c
	@${CC} ${FLAGS} -I ${HEADER} -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
	@echo -e '\033[1;37m[COMPILING]\033[m'
	@${CC} ${FLAGS} ./main.c ${OBJS} -o ${NAME}
	@echo -e '\033[1;32m[DONE]\033[m'

clean:
	@echo -e "\033[1;31m[CLEANING]\033[m"
	@${RM} ${OBJS}

fclean:		clean
	@echo -e "\033[1;31m[REMOVING BINARY]\033[m"
	@${RM} ${NAME}

re:			fclean all

##################################################################

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


#RED_L = \033[1;31m
#GREEN_L = \033[1;32m
#GREEN = \033[0;32m
#BLUE = \033[0;34m
#RED = \033[0;31m

