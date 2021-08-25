# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 13:47:41 by wszurkow          #+#    #+#              #
#    Updated: 2021/08/25 19:41:11 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol
CC				= gcc
FLAGS			= -Wall -Werror -Wextra -O3
SRCS			= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES		= \
				  fractol_utils.c \
				  fractol_run.c \
				  fractol_hooks.c \
				  fractol_colors.c \
				  fractol_data_init.c


OBJS			= ${SRCS:.c=.o}
%.o: %.c
	${CC} ${FLAGS} -lm -I ./includes -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
	make -C ./ext/minilibx-linux/
	${CC} -o  ${NAME} ${FLAGS} ./main.c ${OBJS} \
		-I ./includes \
		-L ./ext/minilibx-linux/ \
		-lmlx -lXext -lX11 -lm

clean:
	@make clean -C ./ext/minilibx-linux/
	rm -f ${OBJS}

fclean:	clean
	rm -f ./${NAME}

re: fclean all

.PHONY:	all clean fclean re
