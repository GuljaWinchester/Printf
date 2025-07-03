# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gperedny <gperedny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 13:50:25 by gperedny          #+#    #+#              #
#    Updated: 2025/07/03 16:07:56 by gperedny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC= cc
FLAGS = -Wall -Wextra -Werror
SRCS = \


DEPS = printf.h
OBJS = $(SRCS: .c= .o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a libft.a
	ar rcs $(NAME) $(OBJS) libft.a

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) libft.a
	make clean -C  libft

fclean: clean
	@rm -f $(NAME)
	make fclean -C  libft

re: fclean all

.PHONY: all clean fclean re