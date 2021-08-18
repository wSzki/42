# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/15 17:32:31 by wszurkow          #+#    #+#              #
#    Updated: 2021/08/17 02:49:20 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libwsz.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

SRCS	=	wsz_atof.c \
			wsz_atoi_overflow.c \
			wsz_count_lines.c \
			wsz_count_numbers.c \

OBJS	=	${SRCS:.c=.o}

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

.c.o:
	${CC} -c ${CFLAGS} $< -o $@ ${HEADER}

all:		${NAME}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
