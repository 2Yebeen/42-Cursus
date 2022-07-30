# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 13:08:09 by yeblee            #+#    #+#              #
#    Updated: 2022/07/30 10:45:45 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar 
ARFLAGS = rcs

RM = rm -rf

INCLUDES = libft.h

SRCS =  ft_split.c		\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_calloc.c		\
		ft_putstr_fd.c	\
		ft_memset.c		\
		ft_printf.c		\
		ft_checkbase.c	\
		ft_formats.c	\
		ft_printbase.c	\
		ft_printstr.c	

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
