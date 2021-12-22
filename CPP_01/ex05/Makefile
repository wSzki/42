#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/12/22 01:10:08 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= karen
EXTENSION		= cpp
CC				= clang++
DIR_HEADER		= ./
DIR_SRCS 		= ./
FLAGS			= -Wall -Wextra -Werror
RM				= /bin/rm -f
ECHO			= echo -e
SANITIZER		= -fsanitize=address -fsanitize=leak
OBJS			= ${SRCS_FILES:.${EXTENSION}=.o}
SRCS_FILES	    = \
				  ./main.cpp        \
				  ./Karen.cpp        \
all:		${NAME}

objs_msg:
	@${ECHO} "${Y}[ COMPILING OBJS]${_R}"

%.o: %.${EXTENSION} objs_msg
	@${CC} ${FLAGS} -I ${DIR_HEADER} -o $@ -c $<

${NAME}: ${OBJS}
	@${ECHO} "${Y}[ COMPILING BIN]${_R}"
	@${CC} ${SANITIZER} -I ${DIR_HEADER} ${FLAGS} ${OBJS} -o ${NAME}
	@${ECHO} "${G}[ DONE]${_R}"


clean:
	@${ECHO} "${R}[ CLEAN]${_R}"
	@${RM} ${OBJS}

fclean:		clean
	@${ECHO} "${R}[ FCLEAN]${_R}"
	@${RM} ${NAME}

re:			fclean all

.PHONY:\
	all fclean clean re \

BLACK			=	\033[0;30m
R				=	\033[0;31m
G				=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
Y				=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m
BOLD			=	\e[1m
_R				=	\e[0m

#Auto update
#@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"
