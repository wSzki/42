# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 13:47:41 by wszurkow          #+#    #+#              #
#    Updated: 2021/08/10 19:33:03 by wszurkow         ###   ########.fr        #
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
				  fractol_atof.c \


OBJS			= ${SRCS:.c=.o}
%.o: %.c
	${CC} ${FLAGS} -lm -I ./includes -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
	${CC} -o  ${NAME} ${FLAGS} ./main.c ${OBJS} \
		-I ./includes \
		-L ./ext/minilibx-linux/ \
		-lmlx -lXext -lX11 -lm

noflags: fclean ${OBJS} libft ft_printf
	${CC} -o ${NAME} ./main.c  ${OBJS}\
		./externals/libft/libft.a \
		./externals/ft_printf/ft_printf.a \
		-I ./includes
	-L ./externals/ft_minilibx/ \
		-lmlx -lXext -lX11
	./fdf ./test_maps/basictest.fdf

#ft_minilibx:
#make -C ./externals/ft_minilibx/
#cp ./externals/ft_minilibx/libmlx_x86_64.a ./externals/

clean:
	rm -f ${OBJS}
	#make clean -C ./externals/ft_minilibx

fclean: clean
	rm -f ./${NAME}

re: fclean all

.PHONY:	all clean fclean re
