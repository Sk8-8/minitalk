# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 20:29:38 by kguillem          #+#    #+#              #
#    Updated: 2025/01/28 01:12:01 by kguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
CFLAGS += -ggdb
RM =rm -rf
INC_DIR = .
CPPFLAGS = -I $(INC_DIR)
FILES = ft_printf.c ft_putnbr_printf.c ft_hexa.c
OBJS = $(FILES:.c=.o)
LIBFT = libft

ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)
all:	$(NAME)

$(NAME):	$(OBJS)

	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(ARNAME)	$(OBJS)
	$(RANNAME)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

re: fclean all

clean:
	$(RM) $(OBJS)
	$(RM) libft/*.o
fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
.PHONY: all re clean fclean
