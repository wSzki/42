# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 12:57:20 by wszurkow          #+#    #+#              #
#    Updated: 2021/12/29 18:02:01 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES ############
NAME			= claptrap
EXTENSION		= cpp
CC				= c++
ECHO 			= printf
DIR_HEADER		= ./
DIR_SRCS 		= ./
FLAGS			= -Wall -Wextra -Werror -std=c++98
RM				= /bin/rm -f
SANITIZER		= -fsanitize=address
OBJS			= ${SRCS_FILES:.${EXTENSION}=.o}
SRCS_FILES	    = \
				  ./main.cpp \
				  ./ClapTrap.cpp \
				  ./ScavTrap.cpp \


# RULES #################
all:		${NAME}

msg_objs:
		@${ECHO} "${Y}[ COMPILING OBJS] ${_R}\n"

%.o: %.${EXTENSION} msg_objs
	@${ECHO} "${Y}└─ $@\r${_R}"
	@${CC} ${FLAGS} -I ${DIR_HEADER} -o $@ -c $<

${NAME}: ${OBJS}
	@${ECHO} "${Y}[ COMPILING BIN] ${_R}\n"
	@${CC} ${SANITIZER} -I ${DIR_HEADER} ${FLAGS} ${OBJS} -o ${NAME}
	@${ECHO} "${G}[ DONE] ${_R}\n"
	@${ECHO} "${G}└─ ./${NAME}${_R}\n"

clean:
	@${ECHO} "${R}[ CLEAN] ${_R}\n"
	@${RM} ${OBJS}

fclean:		clean
	@${ECHO} "${R}[ FCLEAN] ${_R}\n"
	@${RM} ${NAME}

re:			fclean all

.PHONY:\
	all fclean clean re \

# COLORS ################
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

# MISC #################
#Auto update
#@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

# OS SETTINGS ###########
#OS				= $(shell uname -r | grep arch)
#ifeq (${OS}, "")
	#ECHO = echo
#else
	#ECHO = echo -e
#endif

