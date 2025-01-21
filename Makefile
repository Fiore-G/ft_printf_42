# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: figarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 19:06:42 by figarcia          #+#    #+#              #
#    Updated: 2025/01/06 17:21:29 by figarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
SRCS = ft_printf.c \
       ft_printf_utils.c \
       ft_print_ptr.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR)	$(NAME)	$(OBJS)

%.o: %.c $(HEADER) Makefile
	$(CC)	$(CFLAGS) -c $< -o $@

clean:
	$(RM)	$(OBJS)

fclean: clean
	$(RM)	$(NAME)

re: fclean all

.PHONY: clean fclean re all
