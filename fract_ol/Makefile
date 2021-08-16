# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 13:47:41 by wszurkow          #+#    #+#              #
#    Updated: 2021/08/16 17:55:15 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol
CC				= gcc
FLAGS			= -Wall -Werror -Wextra -fsanitize=address
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

leaks:		${OBJS}
	make -C ./ext/minilibx-linux/
	${CC} -o  ${NAME} ${FLAGS} -fsanitize=address -g ./main.c ${OBJS} \
		-I ./includes \
		-L ./ext/minilibx-linux/ \
		-lmlx -lXext -lX11 -lm
	valgrind ./${NAME} julia \

norme:	fclean
	norminette ./main.c
	norminette ./srcs/*
	norminette ./includes/fractol.h

clean:
	make clean -C ./ext/minilibx-linux/
	rm -f ${OBJS}

fclean:	clean
	rm -f ./${NAME}

re: fclean all

.PHONY:	all clean fclean re
