# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 01:28:11 by marvin            #+#    #+#              #
#    Updated: 2022/04/15 19:52:12 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
ARFLAGS		= rcs

RM			= rm -rf

INCDIR		= ./includes
LIBFT		= ./libft

SRCS		= ./srcs/ft_printf.c	\
			  ./srcs/ft_formats.c	\
			  ./srcs/ft_checkbase.c	\
			  ./srcs/ft_printbase.c	\
			  ./srcs/ft_printstr.c	\

OBJS 		= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a $(NAME)
	@ar rcs $@ $?

all : $(NAME)

clean : 
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re:	clean all

.PHONY: all clean fclean re