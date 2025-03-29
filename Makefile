# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 19:14:46 by kguillem          #+#    #+#              #
#    Updated: 2025/03/29 15:34:44 by kguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#sources files
SRC = server.c client.c
#append .o to each .c files in the SRC
#OBJS := $(SRC:%.c=%.o)
OBJS = ${SRC:.c=.o}
#build target name
NAME = minitalk
#compiler
CC = gcc
#compiler flags
CCFLAGS = -Wall -Wextra -Werror
#include directory == dossier includes
INC_DIR = .
#preprocessor flag
CPPFLAGS = -I $(INC_DIR) -I ft_printf -I ft_printf/libft
#rm
RM = rm -f

#first rull is always "all" she is calling $(NAME)
all: $(NAME)
#NAME
$(NAME): server client

server:    server.o
	@make -C ft_printf
	$(CC) $(CCFLAGS) -g server.o ft_printf/libftprintf.a ft_printf/libft/libft.a -o server

client:    client.o
	@make -C ft_printf
	$(CC) $(CCFLAGS) -g client.o ft_printf/libftprintf.a ft_printf/libft/libft.a -o client
# "%.o" rule compie .c file into corresponding .o file
# "%" is a wildcard for "name of the files without extension"
# $@ = target, here target = .o "$<" = first dependencies here = .c
%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<
#clean delete all .o files
clean:
	$(RM) $(OBJS)
	@make -C ft_printf clean
#after executing clean delete the lib
fclean: clean
	$(RM) server client
	@make -C ft_printf fclean
#delete everything then re create it
re: fclean all
#phony targets
.PHONY: all clean fclean re
