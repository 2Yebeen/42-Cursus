# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 01:28:11 by marvin            #+#    #+#              #
#    Updated: 2022/04/13 01:28:11 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a
RM			= rm -f
SRCS		= ./ft_printf.c ./print_char.c ./print_string.c ./print_nbr.c ./utils.c 
OBJS 		= $(SRCS:.c=.o)
INCS		= .
CC			= gcc
CFALGS		= -Wall -Wextra -Werror -Iinclude

%.o : %.c
	$(CC) $(CFALGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rc $(NAME) $(OBJS)

.PHONEY: clean

all : $(NAME)

clean : 
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean :
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re:	fclean all