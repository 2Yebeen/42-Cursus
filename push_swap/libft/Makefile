# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 11:35:33 by yeblee            #+#    #+#              #
#    Updated: 2022/08/04 16:59:21 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

AR		= ar 
ARFLAGS	= rcs

RM		= rm -rf

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
		ft_strlcat.c		

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

%obj/.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	@$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	@$(RM) $(NAME)

re: 
	@make fclean 
	@make all

.PHONY: all clean fclean re