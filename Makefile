# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gperedny <gperedny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 13:50:25 by gperedny          #+#    #+#              #
#    Updated: 2025/07/09 13:41:13 by gperedny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC= cc
FLAGS = -Wall -Wextra -Werror
SRCS = \
printf.c \
printf_utils.c \


DEPS = ft_printf.h
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	make clean -C  libft

fclean: clean
	@rm -f $(NAME)
	make fclean -C  libft

re: fclean all

.SECONDARY: $(OBJS)
