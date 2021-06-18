# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 13:47:41 by wszurkow          #+#    #+#              #
#    Updated: 2021/06/18 12:28:24 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
CC				= gcc
FLAGS			= -Wall -Werror -Wextra -fsanitize=address
SRCS			= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES		= \

OBJS			= ${SRCS:.c=.o}
%.o: %.c
	${CC} ${FLAGS} -I ./includes -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS} libft ft_printf
	${CC} -o ${NAME} ${FLAGS} ./main.c \
		./externals/libft/libft.a \
		./externals/ft_printf/ft_printf.a \
		-I ./includes

noflags: fclean ${OBJS} libft ft_printf
	${CC} -o ${NAME} ./main.c \
		./externals/libft/libft.a \
		./externals/ft_printf/ft_printf.a \
		-I ./includes

libft:
	make -C ./externals/libft/

ft_printf:
	make -C ./externals/ft_printf/

#ft_minilibx:
#make -C ./externals/ft_minilibx/
#cp ./externals/ft_minilibx/libmlx_x86_64.a ./externals/

clean:
	rm -f ${OBJS}
	make clean -C ./externals/libft
	make clean -C ./externals/ft_printf
	#make clean -C ./externals/ft_minilibx

fclean: clean
	rm -f ./externals/libft/libft.a
	rm -f ./externals/ft_printf/ft_printf.a
	rm -f ./fdf

re: fclean all

.PHONY:	all clean fclean re
