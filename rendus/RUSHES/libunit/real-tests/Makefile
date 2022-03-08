# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 13:17:34 by wszurkow          #+#    #+#              #
#    Updated: 2022/01/09 22:52:53 by ggiquiau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME           = libunit_test

CC             = cc
RM             = rm -f

CFLAGS         = -Wall -Wextra -Werror
LFLAGS         = -L $(FRAMEWORK_PATH) -lunit


FRAMEWORK_PATH = ../framework
TO_TEST_PATH   = ../to_test

HEADERS        =  ${FRAMEWORK_PATH}/includes/libunit.h

TEST_HEADERS   = ./get_next_line/gnl_tests.h
TO_TEST_LIB_NAME = lib_to_test.a

INCLUDES       = -I ${FRAMEWORK_PATH}/includes \
				 -I ${TO_TEST_PATH}

SRCS           = main.c \
					$(addprefix get_next_line/,\
					00_launcher.c \
					01_basic_test.c \
					02_invalid_fd.c \
					03_basic_test_one.c \
					04_multiple_fd.c \
					05_null_test.c \
					06_return_check.c\
					07_no_nl.c \
					08_empty.c \
					09_unicode_test.c\
					10_special_chars_test.c\
					11_null_line_if_error.c\
					12_open_folder_instead_file.c\
					13_protected_file.c\
					14_many_newlines.c\
					15_empty_ret.c)

OBJS           = ${SRCS:.c=.o}
OBJS_DIR       = ./srcs/objs/

ifdef D # Make D=1
	CFLAGS = -Wall -Wextra -g3
endif

%.o:    %.c ${HEADERS}
	${CC} -c ${CFLAGS} ${INCLUDES} -o $@ $<

all:            ${NAME}

${NAME}:	${OBJS}
			@make -C ${TO_TEST_PATH}
			@make -C ${FRAMEWORK_PATH}
			${CC} ${CFLAGS} ${INCLUDES} -o $@  $^ ${LFLAGS} ${TO_TEST_PATH}/${TO_TEST_LIB_NAME}

clean:
	${RM} ${OBJS}
	${MAKE} clean -C ${FRAMEWORK_PATH}
	${MAKE} clean -C ${TO_TEST_PATH}

fclean:
	${RM} ${OBJS} ${NAME}
	${MAKE} fclean -C ${FRAMEWORK_PATH}
	${MAKE} fclean -C ${TO_TEST_PATH}

re:
	${MAKE} fclean
	${MAKE} all

test: all
	@./${NAME}

.PHONY:            all clean fclean re
