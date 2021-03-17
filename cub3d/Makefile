# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/03/13 17:42:04 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d.a
SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES	= \
			  gnl.c \
			  cub3d_entrypoint.c \
			  utils/is_in_charset.c \

OBJS		= ${SRCS:.c=.o}
%.o: %.c
				clang -Wall -Werror -Wextra -I ./includes -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
				make -C ./libft
				cp ./libft/libft.a ./${NAME}
				ar -rcs ${NAME} ${OBJS}

exec:		cub3d.a
				@clang -Wall -Werror -Wextra main.c cub3d.a \
					-I ./includes \
					-I /usr/local/include/  \
					-L /usr/local/lib/ \
					-lXext -lX11 -lmlx
				@echo "Creating and executing ./a.out"
				@echo "#####################################"
				@./a.out

clean:
				rm -f ${OBJS}
				make clean -C ./libft
				rm ./a.out

fclean:		clean
				rm -f ./${NAME}
				make fclean -C ./libft
				rm ./a.out

re:			fclean all

.PHONY: 		all fclean clean re

