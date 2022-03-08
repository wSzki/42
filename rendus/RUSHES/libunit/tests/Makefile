# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 13:17:34 by wszurkow          #+#    #+#              #
#    Updated: 2022/01/09 22:52:37 by ggiquiau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME           = libunit_test

CC             = cc
RM             = rm -f

CFLAGS         = -Wall -Wextra -Werror
LFLAGS         = -L $(FRAMEWORK_PATH) -lunit


FRAMEWORK_PATH = ../framework

HEADERS        = ${FRAMEWORK_PATH}/includes/libunit.h

TEST_HEADERS   = ./ft_strjoin/ft_strjoin_tests.h

INCLUDES       = -I ${FRAMEWORK_PATH}/includes

SRCS           = main.c \
					$(addprefix ft_strjoin/,\
					ft_strjoin_test_func.c \
					00_launcher.c \
					01_basic_test_hello_world.c \
					02_basic_test_empty_strings.c \
					03_basic_test_special_chars.c \
					04_basic_test_unicode.c\
					05_basic_test_wrong_pointer.c\
					06_basic_test_bus_error.c)

OBJS           = ${SRCS:.c=.o}

ifdef D # Make D=1
	CFLAGS = -Wall -Wextra -g3
endif

%.o:    %.c ${HEADERS}
	${CC} -c ${CFLAGS} ${INCLUDES} -o $@ $<

all:            ${NAME}

${NAME}:	${OBJS}
			@make -C ${FRAMEWORK_PATH}
			${CC} ${CFLAGS} ${INCLUDES} -o $@  $^ ${LFLAGS}


clean:
	${RM} ${OBJS}
	${MAKE} clean -C ${FRAMEWORK_PATH}

fclean:
	${RM} ${OBJS} ${NAME}
	${MAKE} fclean -C ${FRAMEWORK_PATH}

re:
	${MAKE} fclean
	${MAKE} all

test: all
	@./${NAME}

.PHONY:            all clean fclean re
