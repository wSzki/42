#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/06/12 14:31:14 by wsz              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk.a
SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES	= \
			  main.c

OBJS		= ${SRCS:.c=.o}
%.o: %.c
	gcc -Wall -Werror -Wextra -I ./includes -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
	make -C ./printf
	cp ./printf/libftprintf.a ./ft_printf.a
	ar -rcs ${NAME} ${OBJ}
	@gcc -o minitalk -fsanitize=address -Wall -Werror -Wextra -I ./includes

clean:
				@rm -f ${OBJS}
				@make clean -C ./printf

fclean:			clean
				@rm -f ${NAME}
				@make fclean -C ./printf

re:				fclean all


.PHONY: 		all fclean clean re


