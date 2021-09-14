#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/09/14 18:56:35 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell
CC				= gcc
HEADER			= ./includes
FLAGS			= -Wall -Wextra -Werror -fsanitize=address
THREAD_CHECK	= -fsanitize=thread
LEAK_CHECK		= -fsanitize=address -fsanitize=leak
VALGRINDERS		= -ggdb3
OPTIMIZERS		= -O3
RM				= /bin/rm -f

SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES	= \
			  libft/ft_split.c \
			  libft/ft_strlen.c \
			  libft/ft_putstr.c \
			  libft/ft_strncmp.c \
			  libft/ft_strcmp.c \
			  libft/ft_strjoin.c \
			  \
			  utils/execute.c \
			  utils/find_absolute_path.c \
			  utils/extract_string.c \
			  \
			  pipex/call_child.c \
			  pipex/call_parent.c \
			  pipex/pipex.c \
			  \
			  builtins/pwd.c \
			  builtins/echo.c \
			  builtins/cd.c \
			  builtins/exit.c \
			  \
			  parsing/split_at_operators.c \

OBJS		= ${SRCS:.c=.o}

%.o: %.c
	@${CC} ${FLAGS} -I ${HEADER} -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
	@echo -e '\033[1;37m[COMPILING]\033[m'
	@${CC} ${FLAGS} ./main.c -lreadline ${OBJS} -o ${NAME}
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

