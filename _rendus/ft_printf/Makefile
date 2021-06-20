# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 22:40:46 by wszurkow          #+#    #+#              #
#    Updated: 2021/06/17 14:10:29 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_printf.a
SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES	= \
				ft_printf.c \
				ft_printf_character.c \
				ft_printf_string.c \
				ft_printf_number.c \
				ft_printf_utils.c \
				ft_printf_putnbr_base.c \
				ft_printf_atoi.c \
				ft_printf_parsers.c \

OBJS		= ${SRCS:.c=.o}
%.o: %.c
				clang -Wall -Werror -Wextra -I ./includes -o $@ -c $<

all:		${NAME}

${NAME}:	${OBJS}
				ar -rcs ft_printf.a ${OBJS}

clean:
				rm -f ${OBJS}

fclean:		clean
				rm -f ./ft_printf.a

re:			fclean all

.PHONY: 		all fclean clean re
