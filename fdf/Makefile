# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 13:47:41 by wszurkow          #+#    #+#              #
#    Updated: 2021/06/17 14:34:54 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
COMPILER		= gcc
FLAGS			= -Wall -Werror -Wextra -fsanitize=address
SRCS			= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES		= \
				gnl.c

OBJS			= ${SRCS:.c=.o}
%.o: %.c
	${COMPILER} ${FLAGS} -I ./includes -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS} libft printf ft_minilibx
	${COMPILER} -o ${NAME} ${FLAGS} ./main.c ./externals/*.a -I ./includes

ft_libft:
	make -C ./externals/ft_libft/
	cp ./externals/ft_libft/ft_libft.a ./externals/

ft_printf:
	make -C ./externals/ft_printf/
	cp ./externals/ft_printf/ft_printf.a ./externals/

ft_minilibx:
	make -C ./externals/ft_minilibx/
	cp ./externals/ft_minilibx/libmlx_x86_64.a ./externals/

clean:
	rm -f ${OBJS}
	make clean -C ./externals/*

fclean: clean
	rm -f ./externals/*.a

re: fclean all

.PHONY:	all clean fclean re
