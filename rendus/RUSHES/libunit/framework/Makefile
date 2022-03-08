# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 13:17:34 by wszurkow          #+#    #+#              #
#    Updated: 2022/01/09 22:12:42 by ggiquiau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME          = libunit.a
CC            = cc
RM            = rm -f
CFLAGS        = -Wall -Wextra -Werror
LFLAGS        = -L ${LIBFTPATH} -lft
OBJS_DIR      = ./srcs/objs
HEADERS       = ./includes/libunit.h
LIBFT_PATH    = ./ft_libft
INCLUDES      = \
				-I ./includes \
				-I ${LIBFT_PATH}
SRCS          = $(addprefix srcs/, \
				load_test.c \
				launch_test.c \
				buff.c \
				exit_error.c \
				lutoa.c)
OBJS            = ${SRCS:srcs%.c=${OBJS_DIR}%.o}

ifdef D
	CFLAGS = -Wall -Wextra -g3
endif

${OBJS_DIR}/%.o:    ./srcs/%.c ${HEADERS}
	@mkdir -p ${OBJS_DIR}
	${CC}  -c ${CFLAGS} ${INCLUDES} -o $@ $<

all:            ${NAME}

${NAME}:        ${OBJS}
	@make -C ./ft_libft
	@cp ./ft_libft/libft.a .
	@ar -rcs libft.a $?
	@mv libft.a ${NAME}

clean:
	${RM} ${OBJS}
	@make clean -C ./ft_libft

fclean:
	${RM} ${OBJS} ${NAME}
	@rm -fd ${OBJS_DIR} || true
	@make fclean -C ./ft_libft

re:
	make fclean
	make all

.PHONY:            all clean fclean re
