# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 20:22:14 by anolivei          #+#    #+#              #
#    Updated: 2023/11/02 20:58:04 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC =	actions.c \
		handling_errors.c \
		handling_forks.c \
		handling_philos.c \
		handling_threads.c \
		handling_time.c \
		main.c \
		philo_utils.c \
		routine.c
OBJS = $(SRC:.c=.o)
CC = gcc -pthread
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

all: ${NAME}

${NAME}: ${OBJS}
	${CC} -lpthread ${CFLAGS} ${OBJS} -o $@

%.o: %.c philosophers.h
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PONY: all clean fclean re
