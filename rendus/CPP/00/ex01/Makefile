#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/12/17 00:28:56 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= phonebook
CC				= clang++
HEADER			= ./
FLAGS			= -Wall -Wextra -Werror -fsanitize=address
RM				= /bin/rm -f

SRCS		= $(addprefix ./, ${SRCS_FILES})
SRCS_FILES	= \

OBJS		= ${SRCS:.c=.o}

%.o: %.c
	@${CC} ${FLAGS} -I ${HEADER} -o $@ -c $<


all:		${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} \
		./main.cpp \
		./add.cpp \
		./search.cpp \
		./getters.cpp \
		./setters.cpp \
		${OBJS} -o ${NAME}

clean:
	@${RM}

fclean:		clean
	@${RM} ${NAME}

re:			fclean all

.PHONY:\
	all fclean clean re \

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m
BOLD		=\e[1m
R			=\e[0m

#Auto update
#@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

