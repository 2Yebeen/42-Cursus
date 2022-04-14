# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 01:28:11 by marvin            #+#    #+#              #
#    Updated: 2022/04/14 17:31:51 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar 
ARFLAGS		= rcs

RM			= rm -rf

INCLUDE		= include
LIBFT		= libft
LIBFT_LIB	= libft.a

RM			= rm -rf

SRCS		= ft_printf.c	\
			  ft_formats.c	\
			  ft_printbase.c\
			  ft_printnbr.c	\
			  ft_printstr.c	\

OBJS 		= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFALGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME): $(OBJ)
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)

all : $(NAME)

clean : 
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean :
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re:	fclean all

.PHONY: all clean fclean re norm