# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 10:43:26 by yebeen            #+#    #+#              #
#    Updated: 2022/07/18 10:49:57 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
NAMEB		= pipex_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

LIBFT		= ./libft

SRCS		= pipex.c				\
			  pipex_utils.c	

SRCB		= pipex_bonus.c			\
			  pipex_utils_bonus.c		

OBJS 		= $(SRCS:.c=.o)
OBJB 		= $(SRCB:.c=.o)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT)

all: 		$(NAME)

bonus:		$(NAMEB)

$(NAME): 	$(OBJS)
			@make -C $(LIBFT)
			@$(CC) $(CFLAGS) -L $(LIBFT) -lft $^ -o $@

$(NAMEB): 	$(OBJB)
			@make -C $(LIBFT)
			@$(CC) $(CFLAGS) -L $(LIBFT) -lft $^ -o $@
clean:
			@$(RM) $(OBJS) $(OBJB)
			@make clean -C $(LIBFT)

fclean: 	clean
			@$(RM) $(NAME) $(NAMEB)
			@make fclean -C $(LIBFT)

re:	
			@make fclean 
			@make all

.PHONY: all clean fclean re bonus