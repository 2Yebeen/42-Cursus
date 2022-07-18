# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 13:08:09 by yeblee            #+#    #+#              #
#    Updated: 2022/07/18 13:08:10 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar 
ARFLAGS = rcs

RM = rm -rf

INCLUDES = libft.h		\
		#    ../get_next_line/get_next_line.h

SRCS =  ft_strlen.c		\
		ft_strncmp.c	\
		ft_split.c		\
		ft_strjoin.c	\
		ft_strlcpy.c	\
		ft_strdup.c		\
		ft_strlcat.c	\
		# ../get_next_line/get_next_line.c	\
		# ../get_next_line/get_next_line_utils.c	

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
