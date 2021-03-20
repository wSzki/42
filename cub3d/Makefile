# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/03/20 21:53:55 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d.a
SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES	= \
			  gnl.c \
			  cub3d_entrypoint.c \
			  parsers/parse_input.c \
			  parsers/map/parse_map.c \
			  parsers/map/check_borders.c \
			  parsers/map/check_walls.c \
			  parsers/parameters/parse_line_resolution.c \
			  parsers/parameters/parse_line_paths.c \
			  utils/is_in_charset.c \
			  utils/ft_is_number.c \
			  utils/number_of_args.c \
			  utils/dual_realloc.c \
			  utils/detect_line_map.c \
			  utils/append_error.c \


OBJS		= ${SRCS:.c=.o}
%.o: %.c
	gcc -Wall -Werror -Wextra -I ./includes -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
	make -C ./libft
	cp ./libft/libft.a ./${NAME}
	ar -rcs ${NAME} ${OBJS}

exec:		cub3d.a
	@clear
	@gcc -Wall -Werror -Wextra main.c cub3d.a \
		-I ./includes \
		-I /usr/local/include/  \
		-L /usr/local/lib/ \
		-lXext -lX11 -lmlx
	@echo "Creating and executing ./a.out"
	@echo "#####################################"
	@./a.out

execg:		cub3d.a
	@gcc -g -Wall -Werror -Wextra main.c cub3d.a \
		-I ./includes \
		-I /usr/local/include/  \
		-L /usr/local/lib/ \
		-lXext -lX11 -lmlx
	@echo "Creating and executing ./a.out"
	@echo "#####################################"
	@echo "# SANITIZING [LLDB].................#"
	@echo "#####################################"
	@./a.out

execf:		cub3d.a
	@gcc -fsanitize=address -Wall -Werror -Wextra main.c cub3d.a \
		-I ./includes \
		-I /usr/local/include/  \
		-L /usr/local/lib/ \
		-lXext -lX11 -lmlx
	@echo "Creating and executing ./a.out"
	@echo "#####################################"
	@echo "# SANITIZING [FSANITIZE ADDRESS]....#"
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

