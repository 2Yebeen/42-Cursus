# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 11:35:33 by yeblee            #+#    #+#              #
#    Updated: 2022/08/07 22:53:34 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

AR		= ar 
ARFLAGS	= rcsu

RM		= rm -f

HEADER	= libft.h

SRCS	= 				\
		ft_calloc.c		\
		ft_memset.c		\
		ft_putstr_fd.c	\
		ft_split.c		\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strncmp.c	\
		get_next_line.c	\
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	
re: 
	@make fclean 
	@make all

.PHONY: all clean fclean re