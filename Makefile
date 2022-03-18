# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jting <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 11:47:34 by jting             #+#    #+#              #
#    Updated: 2022/03/18 14:25:24 by jting            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I . -c
RM = rm -f 

SRCS = srcs/ft_hex.c srcs/ft_putptr.c srcs/ft_putstr.c srcs/ft_printf.c srcs/ft_unsign.c

OBJS = $(SRCS:.c=.o)

OBJ_DEST = mv *.o srcs

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS)
	$(OBJ_DEST)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
